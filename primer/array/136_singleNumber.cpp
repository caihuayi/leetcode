#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i = 1;
        int size = nums.size();
        int n = nums[0];    //以空间换时间
        for (; i < size; i++)
        {
            nums[0] ^= nums[i]; 
        }

        return nums[0];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4,1,2,1,2};
    cout << s.singleNumber(nums) << endl;

    return 0;
}