#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    //input
    std::vector<char> s {'h','e','l','l','o' };
    //reverse
    reverse(s.begin(), s.end());

    //output
    for (char x : s)
    {
        std::cout << x << ' ' ;
    }





}
