#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    //input
    std::vector<int> costs{ 1, 3, 2, 4, 1 };
    int coins = 7;
    //holds number of purchases
    int total = 0;

    //sort cost
    sort(costs.begin(), costs.end());

    for (int x : costs)
    {
        if (x <= coins)
        {
            total = total + 1;
            coins = coins - x;
        }
    }
    std::cout << total << std::endl;





}
