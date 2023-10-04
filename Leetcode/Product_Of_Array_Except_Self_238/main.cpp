#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pref = 1;
        int post = 1;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(pref);
            pref = nums[i] * res[i];
        }
        
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res[i] = post * res[i];
            post = nums[i] * post;
        }
        

        return res;
    }
};

int main() {

    Solution s;

    vector<int> nums{1,2,3,4};

    for(auto &it : s.productExceptSelf(nums)) {
        cout << it << " ";
    }

    return 0;
}