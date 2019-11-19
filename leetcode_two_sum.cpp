#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sum;
        unordered_map<int, int> numMap;
        bool found = false;
        int pos = 0;
        for (vector<int>::iterator i = nums.begin(); i != nums.end() && !found; ++i) {
            unordered_map<int, int>::iterator m = numMap.find(target - *i);
            if (m != numMap.end()) {
                found = true;
                sum.emplace_back(m->second);
                sum.emplace_back(pos);
            }
            else {
                numMap.emplace(*i, pos);
            }
            ++pos;
        }
        return sum;
    }
};

/*
 Your input [11,15,3,6,2,8] 9
 Output [2,3]
 Expected [2,3]
 */
