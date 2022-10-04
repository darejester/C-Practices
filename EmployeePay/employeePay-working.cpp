#include<iostream>
#include <string>
#include <vector>
using namespace std;

class employee
{
	private:
		string name;
		string ssn;

	public:
		employee() : name(""),ssn(""){};
		~employee(){};
		
		virtual void print() const = 0;
		void setName(string x)
		{
			name = x;
		}
		void setSsn(string x)
		{
			ssn = x;
		}
		string getName()
		{
			return name;
		}
		string getSsn()
		{
			return ssn;
		}
};
void employee::print() const
{
	cout << "name: " << name << endl;
	cout << "ssn: " << ssn << endl;
}		

class hourly: public employee
{
	private:
		int wage;
		int hours;
		int moneyEarned;
		
	public:
		hourly() : wage(0), hours(0), moneyEarned(0){};
		hourly(int a, int b) {
			wage = a; 
			hours = b;
			
			if(hours > 40)
			{
				moneyEarned = wage * 40;
				moneyEarned += (wage + (wage/2)) * (hours - 40);
			}
			else
			{
				moneyEarned = wage * hours;
			}
			
		}
		~hourly(){};
		
		void print()const
		{
			employee::print();
			cout << "wage: " << wage << endl;
			cout << "hours: " << hours << endl;
			cout << "money: " << moneyEarned << endl;
		}
		
		
		
};

class salaried: public employee
{
	private:
		double yearly;
		double weekly;
			
	public:
		salaried() : yearly(0), weekly(0){};
		salaried(int a){
			yearly = a;
			weekly = (yearly/52);
			
		}
		~salaried(){};
		
		void print()const
		{
			employee::print();
			cout << "yearly: " << yearly << endl;
			cout << "weekly: " << weekly << endl;
		}
		
};

class roster
{
	private:
		vector<employee*> a;
		
	public:
		//roster(hourly x){};
		//roster(salaried x){};
		roster(){};
		~roster(){};
		
		bool findMatch(string ssn){
			bool match = 0;
			for(employee *x: a)
			{
				if(ssn == x->getSsn())
				{
					return true;
				}
			}
			return false;
		}
		
		void add(employee &x){
			string name = "";
			string ssn ="";
			cout << "put in name: ";
			cin >> name;
			cout << "put in ssn: ";
			cin >> ssn;
			
			while(findMatch(ssn))
			{
				cout << "Cant put in the same person with the same SSN" << endl;
				cout << "put in name: ";
				cin >> name;
				cout << "put in ssn: ";
				cin >> ssn;
			}
			
			x.setName(name);
			x.setSsn(ssn);
			a.push_back(&x);
			cout << endl;
		}
		
		void remove(string ssn){
			int ind= 0;
			vector<employee*>::iterator iter = a.begin();
			if(findMatch(ssn))
			{
				for(int i = 0; a[i]->getSsn() != ssn; i++)
				{
					iter++;
				}
				a.erase(iter);
			}
			else
			{
				cout << "person not in the roster" << endl;
			}
		}
		
		void print(){
			cout << "ROSTER:" << endl;
			for(employee *x: a)
			{
				x->print();
				cout << endl;
			}
		}
};


int main()
{
	roster x;
	hourly a(10, 41);
	salaried b(1);
	//b.print();
	x.add(b);
	x.add(a);

	x.print();
	x.remove("10");
	
	cout << "=====AFTER REMOVING=====" << endl;
	x.print();
	

}
