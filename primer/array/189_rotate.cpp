#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int *buf = new int[k];
        int i, j;
        while (size-k < 0)
        {
            k-=size;
        }
        for (i = size-k; i < size; i++)
        {
            for (int l = 0; l < size; l++)
            {
                cout << nums[l] << " ";
            }
            cout << endl;
            //cout << "buf[" << i+k-size << "]=" << nums[i] << endl;
            buf[i+k-size] = nums[i];
            for (j = i; j >= 0; j-=k)
            {
                if (j-k >= 0)
                {
                    nums[j] = nums[j-k];
                }
            }
        }
        for (i = 0; i < k; i++)
        {
            nums[i] = buf[i];
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr = {-1};
    s.rotate(arr, 2);
    for (auto s : arr)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}