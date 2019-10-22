#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int i, j;
        int n;
        int num;
        for (i = 0; i < slots1.size(); i++)
        {
            if (slots1[i][1]-slots1[i][0] < duration) continue;
            for (j = 0; j < slots2.size(); j++)
            {
                if (slots2[j][1]-slots2[j][0] < duration) continue;
                if (slots2[j][0] >= slots1[i][0] && slots2[j][0] < slots1[i][1])
                {
                    num = slots1[i][1]-slots2[j][0] - duration;
                    if (num > 0)
                    {
                        if (slots2[j][0] < n)
                            n = slots2[j][0];
                    }
                }
                else if (slots2[j][1] > slots1[i][0] && slots2[j][1] <= slots1[i][1])
                {
                    num = slots2[j][1]-slots1[i][0]-duration;
                    if (num > 0)
                    {
                       if (slots1[i][0] < n)
                        {
                            n = slots1[i][0];
                        }
                    }
                }
            }
        }
        vector<int> a = {n, n+duration};
        return a;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> slots1 = {{10,50},{60,120},{140,210}};
    vector<vector<int>> slots2 = {{0,15},{60,70}};
    vector<int> arr = s.minAvailableDuration(slots1, slots2, 8);
    cout << arr[0] << endl;

    return 0;
}