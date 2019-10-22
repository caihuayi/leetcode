#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double x1 = coordinates[0][0];
        double y1 = coordinates[0][1];
        double x2, y2;
        int i = 2;
        double k;
        if (coordinates[1][0]-coordinates[0][0] != 0)
        {
            k = (coordinates[1][1]-coordinates[0][1]) / (coordinates[1][0]-coordinates[0][0]);
        }
        else
        {
            k = 999999;
        }
        for (i; i < coordinates.size(); i++)
        {
            x2 = coordinates[i][0];
            y2 = coordinates[i][1];
            if (x2-x1 != 0)
            {
                if (k != (y2-y1)/(x2-x1))
                {
                    return false;
                }
            }
            else
            {
                if (k != 999999)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {{1,2},{2,3},{3,6},{4,5}, {5,6},{6,7}};
    cout << s.checkStraightLine(v) << endl;

    return 0;
}