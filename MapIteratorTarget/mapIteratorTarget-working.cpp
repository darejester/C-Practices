#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <iomanip>
using namespace std;



//finds all occurances f val in m's int
vector< map<string, int>::const_iterator >
val_count(const map<string, int>& m, int val)
{
	vector< map<string, int>::const_iterator > v;
	map<string, int>::const_iterator itr;

	for (itr = m.begin(); itr != m.end(); ++itr) //goes into each element of database
	{
		if (itr->second == val)
		{
			v.push_back(itr);

		}
	}

	return v;
}

void print(vector< map<string, int>::const_iterator > v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i]->first << " " <<v[i]->second << endl;
	}

}

void fillMap(map<string, int>& map)
{
	map.insert({ "a",1 });
	map.insert({ "b",1 });
	map.insert({ "c",2 });
}


int main()
{
	//argument
	map<string, int> arg;
	vector< map<string, int>::const_iterator > vec;
	int x = 1;

	//fill map
	fillMap(arg);

	//count occurances of x in arg and store it in vec
	vec = val_count(arg, x);

	//print vector of map iterators
	print(vec);


}
