#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int get_count(vector<string>& strs)
    {
        int n = 0;
        while(1)
        {
            char c = strs[0][n];
            if (n >= strs[0].length()) return n;
            cout << n;
            for (auto& ps : strs)
            {
                if (n >= ps.length()) return n;
                if (c == ps[n])
                {
                    //cout << c << endl;
                }
                else
                {
                    return n;
                }
                
            }
            n++;
        }
        return n;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int n = get_count(strs);
        cout << "n = " << n << endl;
        
        if (n == 0)
        {
            return "";
        }
        return strs[0].substr(0, n);
    }
};

int main()
{
    Solution s;
    vector<string> vstr = {"aa","a"};
    cout << s.longestCommonPrefix(vstr) << endl;

    return 0;
}