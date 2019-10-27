#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        char temp;
        for (int i = 0; i < size/2; i++)
        {
            temp = s[i];
            s[i] = s[size-i-1];
            s[size-i-1] = temp;
        }
    }
};

int main()
{
    Solution s;
    vector<char> arr = {'h','e','l','l','o'};
    s.reverseString(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}