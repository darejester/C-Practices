#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> finder(std::vector<int>& nums, int target) {

    std::vector<std::pair<int, int>> v;

    std::vector<int> v2;
    //first = value, second = index
    std::pair<int, int> p;
    //loads p with values and indexes and loads it into v
    for (int i = 0; i < nums.size(); i++) {
        p.first = nums[i];
        p.second = i;
        v.push_back(p);
    }
    //sort v
    sort(v.begin(), v.end());
    //create beginning and end iterators
    auto it = v.begin(), it2 = v.end();
    //decrement end iterator, so it points to last element
    it2--;
    //loop through v to check which numbers meet the target
    while (it < it2) {
        int sum = it->first + it2->first;
        if (sum == target) {
            v2.push_back(it->second);
            v2.push_back(it2->second);
            return v2;
        }
        else if (sum < target)
            it++;
        else
            it2--;
    }

    return v2;
}

int main()
{
    int target = 9;
    std::vector<int> nums = { 2,7,11,15 };
    std::vector<int> out = finder(nums, target);
    for (int x : out)
    {
        std::cout << x << std::endl;
    }
}


