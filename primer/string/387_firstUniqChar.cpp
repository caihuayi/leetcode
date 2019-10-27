#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> ma;
        int size = s.size();
        int i = 0;
        for (; i < size; i++)
        {
            if (ma.find(s[i]) == ma.end())
            {
                ma.insert({s[i], i});
            }
            else
            {
                ma.find(s[i])->second += size;
            }
        }
        int result = size;
        for (const auto& iter : ma)
        {
            result = iter.second < result ? iter.second : result;
        }
        if (result >= size) result = -1;
        return result;
    }
};

int main()
{
    Solution s;
    string str = "aadadaad";
    cout << s.firstUniqChar(str) << endl;

    return 0;
}