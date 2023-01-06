#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    //input
    std::string s = "MDCCCLXXXIV";
    //container for integer
    int num = 0;

    //loop through the whole string
    for (int x = 0; x < s.size();x++)
    {
        //checks for what roman character 
        if (s[x] == 'I')
        {
            // subtraction
            if (s[x + 1] == 'V')
            {
                num = num + 4;
                x = x+1;

            }
            else if (s[x + 1] == 'X')
            {
                num = num + 9;
                x = x+1;
            }
            else
            {
                num = num + 1;
            }  
        }
        else if (s[x] == 'V')
        {
            num = num + 5;
        }
        else if (s[x] == 'X')
        {
            if(s[x + 1] == 'L')
            {
                num = num + 40;
                x = x+1;
            }
            else if (s[x + 1] == 'C')
            {
                num = num + 90;
                x = x+1;
            }
            else
            {
                num = num + 10;
            }
        }
        else if (s[x] == 'L')
        {
            num = num + 50;
        }
        else if (s[x] == 'C')
        {
            if (s[x + 1] == 'D')
            {
                num = num + 400;
                x = x+1;
            }
            else if (s[x + 1] == 'M')
            {
                num = num + 900;
                x = x+1;
            }
            else
            {
                num = num + 100;
            }
        }
        else if (s[x] == 'D')
        {
            num = num + 500;
        }
        else if (s[x] == 'M')
        {
            num = num + 1000;
        }
    }

    std::cout << num << std::endl;


}
