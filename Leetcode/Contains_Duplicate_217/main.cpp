#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        
        for(auto it : nums)
        {
            if(!uset.insert(it).second)
            {
                return true;
            }
        }
        return false;
    }
};


int main() {

    vector<int> nums{1,1,1,3,3,4,3,2,4,2};

    Solution s;
    cout << s.containsDuplicate(nums);
    
    return 0;
}