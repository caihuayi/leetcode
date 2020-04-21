#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        int tail = nums1.size()-1;
        int tail1 = m-1;
        int tail2 = n-1;
        while (tail >= 0 && tail1 >= 0 && tail2 >= 0)
        {
            if (nums1[tail1] > nums2[tail2])
            {
                nums1[tail--] = nums1[tail1--];
            }
            else
            {
                nums1[tail--] = nums2[tail2--];
            }
        }
        if (tail1 < 0)
        {
            while (tail >= 0)
            {
                nums1[tail--] = nums2[tail2--];
            }
        }
    }
};

int main()
{
    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};
    Solution s;
    s.merge(nums1, 1, nums2, nums2.size());
    for (auto& i : nums1)
    {
        cout << i << " " << endl;
    }

    return 0;
}