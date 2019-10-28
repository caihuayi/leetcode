#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        int i = 0;
        int j = s.size()-1;
        while (j > i)
        {
            while (!((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) && i < j)
            {
                i++;
                cout << "i";
            }
            while (!((s[j]>='0' && s[j]<='9') || (s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z')) && i < j)
            {
                j--;
                cout << "j";
            }
            cout << i << " " << j << endl;
            if ((s[i] != s[j]) && (s[i]-'a'+'A' != s[j]) && (s[i]-'A'+'a' != s[j]))
            {
                return false;
            }
            if ((s[i] <= '9' && s[j] > '9') || (s[i] > '9' && s[j] <= '9'))
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    Solution sl;
    string s = "0P";
    cout << sl.isPalindrome(s) << endl;

    return 0;
}