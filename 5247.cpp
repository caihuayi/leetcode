#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> odds;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]%2 == 1)
            {
                odds.push_back(i);
            }
        }
        if (odds.size() < k)
        {
            return 0;
        }
        else if(odds.size() == k)
        {
            result = (odds[0]+1)*(nums.size()-odds[k-1]);
            return result;
        }
        else
        {
            int lo, hi;
            for (lo = 0, hi = lo+k; hi < odds.size()+1; lo++, hi++)
            {
                if (lo == 0)
                {
                    result += (odds[lo]+1)*(odds[hi+1]-odds[hi]);
                }
                else if (hi == odds.size())
                {
                    result += (odds[lo]-odds[lo-1])*(nums.size()-odds[hi-1]);
                }
                else
                {
                    result += (odds[lo]-odds[lo-1])*(odds[hi+1]-odds[hi]);
                }
                cout << result << endl;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 1;
    cout << s.numberOfSubarrays(nums, k) << endl;

    return 0;
}