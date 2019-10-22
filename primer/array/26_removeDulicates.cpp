#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return nums.size();
        if (nums.size() == 1) return nums.size();
        int i = 0;
        int j;
        for (j = 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[i])
            {
                nums[++i] = nums[j];
            }
        }

        return i+1;
    }
};

int main()
{
    Solution s;
    vector<int> arr;
    cout << s.removeDuplicates(arr) << endl;

    return 0;
}