#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string palindromeProblem(string s);

int main() {
    string testString = "aaacodoc";
    palindromeProblem(testString);
    return 0;
}

string palindromeProblem(string s)
{
    string prefix = "";
    string palindrome = "";
    while(s.length() > 0)
    {
        for (int i = 0; i < s.length(); i++)
        {
            //check if prefix length < 1
            if(prefix.length() < 1)
            {
                //add first two character of s
                prefix += s[0];
            }
            else
            {
                //add char to prefix
                prefix += s[i];
                //cout << "prefix: " << prefix << endl;

                //check if prefix is a palindrome
                //reverse prefix
                string reversedPrefix = prefix;
                reverse(reversedPrefix.begin(), reversedPrefix.end());
                //cout << "reversedPrefix: " << reversedPrefix << endl;

                if(prefix == reversedPrefix)
                {
                    palindrome = prefix;

                }

            }
        }
        //remove palindrome from s
        for(char character : palindrome)
        {
            s.erase(s.begin());
        }
        //check if palindrome is empty
        if(palindrome.empty())
        {
            cout << "S:" << s << endl;
            return s;
        }
        //empty palindrome and prefix
        cout << "palindrome: "<< palindrome << endl;
        palindrome = "";
        prefix = "";
    }


    cout << "S:" << s << endl;
    return s;
}
