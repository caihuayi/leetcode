#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        if (s_size != t_size)
        {
            return false;
        }
        int a[26] = {0};
        int i;
        for (i = 0; i < s_size; i++)
        {
            a[s[i]-'a']++;
        }
        for (i = 0; i < t_size; i++)
        {
            if (--a[t[i]-'a'] < 0)
            {
                return false;
            }
        }
        
        return true;
    }
};

int main()
{
    Solution sl;
    string s = "anaggram";
    string t = "nagazam";
    cout << sl.isAnagram(s, t) << endl;

    return 0;
}