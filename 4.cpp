#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int lo1 = 0;
    int lo2 = 0;
    int hi1 = nums1.size()-1;
    int hi2 = nums2.size()-1;
    while(1)
    {
        if (nums1[lo1] < nums2[lo2] && lo1 < hi1)
        {
            lo1++;
        }
        else if (nums1[lo1 >= nums2[lo2] && lo2 < hi2])
        {
            lo2++;
        }
        if (nums1[hi1] > nums2[hi2] && lo1 < hi1)
        {
            hi1--;
        }
        else if (nums1[hi1] <= nums2[hi2] && lo2 < hi2)
        {
            hi2--;
        }
    }
}

int main()
{
    vector<int> num1;
    vector<int> num2;

    return 0;
}