#include <iostream>
#include <string>
using namespace std;

class Solution {

public:
    int myAtoi(string str) {
        int i = 0;
        int start = 0;
        int lo, hi;
        int minus = 0;
        int result = 0;
        for (i = 0; i < str.length(); i++)
        {
            // is num?
            //cout << minus << endl;
            if ('0' <= str[i] && '9' >= str[i])
            {
                start = 1;
                lo = i;
                if (minus == 0 && ((result > INT_MAX/10) || (result == INT_MAX/10 && str[i]-'0' > 7)))
                {
                    //cout << "up flow" << endl;
                    return INT_MAX;
                }
                if (minus == 1 && ((result < INT_MIN/10) || (result == INT_MIN/10 && str[i]-'0' > 8))) 
                {
                    //cout << "down flow" << endl;
                    return INT_MIN;
                }
                //cout << str[i] - '0' << endl;
                
                if (minus == 1)
                {
                    //if (result > 0) result = -result;
                    result = result*10 - (str[i] - '0');
                    cout << result << endl;
                }
                else
                {
                    result = result*10 + (str[i] - '0');
                }
                
            } 
            // is space?
            else if(str[i] == ' ' && start == 0)
            {
                
            }
            // is minus
            else if(str[i] == '-' && str[i+1] >= '0' && str[i+1] <= '9' && start == 0)
            {
                minus = 1;
                //cout << "is minus" << endl;
            }
            // is add
            else if (str[i] == '+' && str[i+1] >= '0' && str[i+1] <= '9' && start == 0)
            {

            }
            // letter
            else
            {
                break;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    //cout << INT_MAX << endl;
    //cout << INT_MIN << endl;
    cout << s.myAtoi("-2147483648") << endl;

    return 0;
}