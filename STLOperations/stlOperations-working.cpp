#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <vector>
#include <iterator>
#include <iomanip>
#include <regex>

using namespace std;
/*
(a) Store the above data in an appropriate STL container. 
(b) Ask the user for a keyword (could be a part of the artist name or song title) and print out all entries that contain that keyword. 
(c) Print out all of the songs in the database in alphabetical order (don't list titles more than once) and give how many times that song occurs in the database.

multimap
need to be able to search using name or title
print all songs in the database in alphabetical order (vector?)
*/

//fills data base with data
void setDatabase(multimap<string, string> &map)
{
	map.insert({"Spitboy", "True Self"});
	map.insert({"Spitboy", "In Your Face"});
	map.insert({"Lil Wayne", "In Your Face"});
	map.insert({"Chaos UK", "Victimized"});
	map.insert({"Chaos UK", "Kin for a Day"});
	map.insert({"UB40", "Johnny Too Bad"});
	map.insert({"UB40", "Red Red Wine"});
	map.insert({"Neil Diamond", "Red Red Wine"});
	map.insert({"Incubus", "Admiration"});
	map.insert({"Johnboy", "Admiration"});
	map.insert({"Jawbreaker", "Kiss the Bottle"});
	map.insert({"Minor Threat", "Straight Edge"});
	map.insert({"Bikini Kill", "Rebel Girl"});
	map.insert({"MC 900 Foot Jesus", "Killer Inside me"});
	map.insert({"Sonic Youth", "Kill Yr Idols"});
	map.insert({"Husker Du", "Eight Miles High"});
	map.insert({"Butch Hancock", "One Kiss"});
	map.insert({"Butch Hancock", "Already Gone"});
	map.insert({"The Clash", "Complete Control"});
	
}

//prints out database in aphabetical order
void print(multimap<string, string> &map)
{
	//declare an iterator for multimap
	multimap<string, string>::iterator itr;
	
	cout << setw(20) << left << "ARTIST" << setw(20) << left << "SONG" << '\n';
	
	for (itr = map.begin(); itr != map.end(); ++itr) 
	{
        cout << setw(20) << left << itr->first << setw(20) << left << itr->second << '\n';
	}
}

//store all songs removing repetitions and prints it
void songs(multimap<string, string> &map)
{
	//stores songs and the number it appears
	multimap<string, int> songList;
	//iterator to go through database
	multimap<string, string>::iterator itr;
	multimap<string, int>::iterator itr2;
	
	for (itr = map.begin(); itr != map.end(); ++itr) //goes into each element of database
	{
        if(songList.find(itr->second) == songList.end())//if not in songList
        {
        	songList.insert({itr->second, 1});
		}
		else//if in songList
		{
			songList.find(itr->second)->second++;
		}
	}
	
	//print songList with the title and times it occured
	cout << setw(20) << left << "SONG" << setw(20) << left << "TIMES OCCURED" << '\n';
	for (itr2 = songList.begin(); itr2 != songList.end(); ++itr2) 
	{
        cout << setw(20) << left << itr2->first << setw(20) << left << itr2->second << '\n';
	}
}


//search database for keyword
void search(multimap<string, string> &map,string x)
{
	//iterator to iterate through database
	multimap<string, string>::iterator itr;
	
	cout << "looking for: " << x << endl;
	
	for (itr = map.begin(); itr != map.end(); ++itr) //goes into each element of database
	{
        if(itr->first.find(x) != string::npos || itr->second.find(x) != string::npos) // if x is found in database (either in first or second)
        {
        	cout << setw(20) << left << itr->first << setw(20) << left << itr->second << '\n';
		}
		else if(itr == map.end())
		{
			cout << "No occurance in the database" << endl;
		}
		else//if in database
		{
			//cout << "hi" << endl;
			continue;
		}
	}
}

int main()
{
	//map to hold database
	multimap<string, string> database;
	
	//fill database
	setDatabase(database);
	
	print(database);
	cout << endl;
	
	songs(database);
	cout << endl;
	
	search(database,"mi");
}
