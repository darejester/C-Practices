#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

long long solution(vector<string> queryType, vector<vector<int>> query);

int main() {
    vector<string> queryType{"insert", "insert", "addToValue", "addToKey", "get"};
    vector<vector<int>> query{{1, 2},{2, 3}, {2}, {1}, {3}};

    solution(queryType,query);
    return 0;
}

long long solution(vector<string> queryType, vector<vector<int>> query)
{
    map<int,int> hashMap;
    long long sum;

    for(int index = 0; index < queryType.size(); index++)
    {
        if (queryType[index] == "insert")
        {
            cout << "insert" << endl;
            hashMap[query[index][0]] = query[index][1];

        }
        else if (queryType[index] == "addToValue")
        {
            cout << "addToValue" << endl;
            for(auto &pair : hashMap)
            {
                pair.second = pair.second + query[index][0];
                cout << pair.second << endl;
            }
        }
        else if (queryType[index] == "addToKey")
        {
            cout << "addToKey" << endl;
            for(auto &pair : hashMap)
            {
                auto pairHandler = hashMap.extract(pair.first);
                pairHandler.key() = pairHandler.key() + query[index][0];
                hashMap.insert(std::move(pairHandler));

            }
        }
        else if (queryType[index] == "get")
        {
            cout << "get" << endl;
        }
    }

    // Get an iterator pointing to the first element in the map
    map<int, int>::iterator it = hashMap.begin();

    // Iterate through the map and print the elements
    while (it != hashMap.end())
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }
    return sum;

}
