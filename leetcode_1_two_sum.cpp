#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        vector<int> v;
        int i = 0;
        for (auto x: nums) {
            if (numMap.find(target - x) != numMap.end()) {
                v.push_back(i);
                v.push_back(numMap.find(target - x)->second);
                return v;
            }
            numMap.emplace(x, i);
            ++i;
        }
        return v;
    }
};
