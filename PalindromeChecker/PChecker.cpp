#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    int x = 121;

    //convert x into string
    std::string y = std::to_string(x);
    //to hold reversed y
    std::string z = "";
    //load reversed y to z
    for (int temp = y.size() - 1; temp >= 0 ;temp--)
    {
        z = z + y[temp];
    }
    //check if original string equals reversed string
    if (z == y)
    {
        return true;
    }
    else
    {
        return false;
    }

}

