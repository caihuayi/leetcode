#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int i;
        int j;
        for (i = size-1; i >= size-k; i--)
        {
            for (j = i; j > 0;)
            {
                nums[(j+k)%size] = nums[j];
                cout << (j+k)%size << " " << j << endl;
                j-=k;
            }
            cout << "i: " << i << endl;
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1,2,3,4,5,6,7};
    s.rotate(arr, 2);
    for (auto s : arr)
    {
        cout << s << " ";
    }

    return 0;
}