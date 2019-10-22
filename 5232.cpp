#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        int size = s.size();
        int count = size/4;
        cout << "count:" << count << endl;
        int q = 0;
        int w = 0;
        int e = 0;
        int r = 0;
        char c;
        int ans;
        for (int i = 0; i < size; i++)
        {
            c = s[i];
            cout << c << " ";
            if (c == 'Q')
            {
                if (++q > count)
                {
                    ++ans;
                }
            }
            else if(c == 'W')
            {
                if (++w > count)
                {
                    ++ans;
                }
            }
            else if(c == 'E')
            {
                if (++e > count)
                {
                    ++ans;
                }
            }
            else if(c == 'R')
            {
                if (++r > count)
                {
                    ++ans;
                }
            }
        }
        cout << "Q: " << q << "W: " << w << "E: " << e << "R: " << r << endl;
        return ans;    
    }
};

int main()
{
    Solution s;
    string s1 = "";
    cout << endl << s.balancedString(s1) << endl;;

    return 0;
}