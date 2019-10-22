#include <vector>
#include <iostream>
using namespace std;

int throw_mid(vector<int>& nums, int lo, int hi)
{
    if (hi == lo)
    {
        cout << "single: " << nums[lo] << " " << lo << endl;
        return nums[lo];
    }
    int mid = (lo+hi+1) / 2;
    int suml = throw_mid(nums, lo, mid-1);
    int sumr = throw_mid(nums, mid, hi);
    int t;
    int sum2 = -65535;
    int sum1 = 0;
    int sum = 0;
    //cout << "before for1" << endl;
    for (t = mid; t <= hi; t++)
    {
        sum1 += nums[t];
        if (sum2 < sum1)
        {
            sum2 = sum1;
        }
    }
    sum += sum2;
    sum2 = nums[mid-1];
    sum1 = 0;
    //cout << "before for2" << endl;
    for (t = mid-1; t >= lo; t--)
    {
        sum1 += nums[t];
        if (sum2 < sum1)
        {
            sum2 = sum1;
        }
    }
    //cout << "after for2" << endl;
    sum += sum2;
    cout << "mid: " << sum << " " << mid << endl;
    cout << "lef: " << suml << endl;
    cout << "rig: " << sumr << endl << endl;

    if (sum >=  suml && sum >= sumr) 
    {
        //cout << "middle: " << sum << endl;
        return sum;
    }
    else if(suml >= sumr && suml >= sum) 
    {
        //cout << "left: " << nums[lo] << " " << lo << endl;
        return suml;
    }
    else if(sumr >= sum && sumr >= suml)
    {
        //cout << "right: " << nums[lo] << " " << lo << endl;
        return sumr;
    }
    else
    {
        return sum;
    }
    
}

int maxSubArray(vector<int>& nums)
{
    return throw_mid(nums, 0, nums.size()-1);
}

int main()
{
    vector<int> nums = {-1, -1, -2, -2};
    cout << maxSubArray(nums) << endl;

    return 0;
}