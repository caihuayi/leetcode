#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        if (nums.size() <= 1) return nums.size();
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};

int main()
{
    vector<int> nums;
    Solution s;
    cout << s.removeDuplicates(nums) << endl;

    return 0;
}