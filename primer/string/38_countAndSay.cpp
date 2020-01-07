#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string say(string str)
    {
        char c = str[0];
        int count = 0;
        string result;
        for (auto p : str)
        {
            if (c == p)
            {
                count++;
            }
            else
            {
                if (count < 10)
                {
                    result += ('0'+count);
                }
                else
                {
                    result += ( '0' + count/10);
                    result += ('0' + count%10);
                }
                result += c;
                c = p;
                count = 1;
            }
        }
        if (count < 10)
        {
            result += ('0'+count);
        }
        else
        {
            result += ( '0' + count/10);
            result += ('0' + count%10);
        }
        
        
        result += c;
        count = 1;

        return result;
    }

    string countAndSay(int n) {
        string str = "1";
        for (int i = 0; i < n-1; i++)
        {
            str = say(str);
        }
        return str;
    }
};

int main()
{
    string s = "1112211";
    Solution sl;
    cout << sl.countAndSay(1) << endl;

    return 0;
}