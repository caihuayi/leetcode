#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for (int i = size-1; i >= 0; i--)
        {
            if (digits[i] == 9) 
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                break;
            }
        }
        if (digits[0] == 0)
        {
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};

int main()
{
    Solution s;
    vector<int> v = {9, 9, 9};
    vector<int> r = s.plusOne(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << r[i];
    }
    cout << endl;

    return 0;
}