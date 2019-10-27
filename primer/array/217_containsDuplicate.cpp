#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> in;
        int i;
        int size = nums.size();
        for (i = 0; i < size; i++)
        {
            if (in.find(nums[i]) == in.end())
            {
                in.insert(nums[i]);
            }
            else
            {
                return true;
            }
            
        }        
        return false;
    }
};

int main()
{
    vector<int> arr = {1,2,3};
    Solution s;
    cout << s.containsDuplicate(arr) << endl;

    return 0;
}