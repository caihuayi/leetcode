#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumbe(vector<int>& arr) {
        int minus;
        int size = arr.size();
        if (arr[1]-arr[0] == arr[size-1]-arr[size-2])
        {
            minus = arr[1]-arr[0];
        }
        else
        {
            if (arr[1]-arr[0] > 0)
            {
                minus = (arr[1]-arr[0] < arr[size-1]-arr[size-2]) ? arr[1]-arr[0] : arr[size-1]-arr[size-2];
            }
            else
            {
                minus = (arr[1]-arr[0] > arr[size-1]-arr[size-2]) ? (arr[1]-arr[0]) : (arr[size-1]-arr[size-2]);
            }
        }
        cout << "minus " << minus << endl;
        for (int i = 0; i < size-1; i++)
        {
            if (arr[i+1]-arr[i] != minus) return arr[i]+minus;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {5,7,11,13};
    cout << s.missingNumbe(arr) << endl;;

    return 0;
}