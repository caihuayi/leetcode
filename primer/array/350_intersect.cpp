#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        multiset<int> s;
        int size;
        if (nums1.size() > nums2.size())
        {
            int i;
            size = nums1.size();
            for (i = 0; i < size; i++)
            {
                s.insert(nums1[i]);
            }
            size = nums2.size();
            for (i = 0; i < size; i++)
            {
                if (s.find(nums2[i]) != s.end())
                {
                    s.erase(s.find(nums2[i]));
                    result.push_back(nums2[i]);
                }
            }
        }
        else
        {
            size = nums2.size();
            int i;
            for (i = 0; i < size; i++)
            {
                s.insert(nums2[i]);
            }
            size = nums1.size();
            for (i = 0; i < size; i++)
            {
                if (s.find(nums1[i]) != s.end())
                {
                    s.erase(s.find(nums1[i]));
                    result.push_back(nums1[i]);
                }
            }
        }

        return result;   
    }
};

int main()
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2, 2};
    Solution s;
    vector<int> nums3 = s.intersect(nums1, nums2);
    for (int i = 0; i < nums3.size(); i++)
    {
        cout << nums3[i] << " ";
    }
    cout << endl;

    return 0;
}