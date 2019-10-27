#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int buf;
        int i = 0;
        int j;
        for (; i < size/2; i++)
        {
            for (j = i; j < size-i-1; j++)
            {
               buf = matrix[size-j-1][i];
               matrix[size-j-1][i] = matrix[size-i-1][size-j-1];
               matrix[size-i-1][size-j-1] = matrix[j][size-i-1];
               matrix[j][size-i-1] = matrix[i][j];
               matrix[i][j] = buf;
            }
        }
    }
};

int main()
{
    vector<vector<int>> arr = 
    {
        {15,13, 2, 5},
        {14, 3, 4, 1},
        {12, 6, 8, 9},
        {16, 7,10,11}
    };
    Solution s;
    s.rotate(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}