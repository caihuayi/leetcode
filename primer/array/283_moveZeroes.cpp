#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        int j = 1;
        while(i < size)
        {
            if (nums[i] == 0)
            {
                for (; j < size; j++)
                {
                    if (nums[j] != 0)
                    {
                        nums[i] = nums[j];
                        nums[j] = 0;
                        break;
                    }
                }
            }
            ++j;
            ++i;
        }
    }
};

int main()
{
    vector<int> a = {4,2,4,0,0,3,0,5,1,0};
    Solution s;
    s.moveZeroes(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}