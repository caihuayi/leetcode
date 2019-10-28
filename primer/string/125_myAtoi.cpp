#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
        int i = 0;
        bool is_minus = false;
        bool is_start = false;
        int result = 0;
        while (i < size)
        {
            if ((str[i] == ' ') && is_start == false)
            {   
                
            }
            else if (str[i] == '+' && is_start == false)
            {
                is_start = true;
            } 
            else if (str[i] == '-' && is_start == false)
            {
                is_minus = true;
                is_start = true;
            }
            else if (str[i] >= '0' && str[i] <= '9')
            {
                is_start = true;
                if (is_minus == false)
                {
                    if (result == INT_MAX/10)
                    {
                        if (str[i] >= '7')
                        {
                            return INT_MAX;
                        }
                    }
                    else if(result > INT_MAX/10)
                    {
                        return INT_MAX;
                    }
                    else
                    {
                        
                    }
                    
                }
                else if(is_minus == true)
                {
                    if (result == INT_MAX/10)
                    {
                        if (str[i] >= '8')
                        {
                            return INT_MIN;
                        }
                    }
                    else if(result > INT_MAX/10)
                    {
                        return INT_MIN;
                    }
                    else
                    {
                        
                    }
                }
                else
                {
                    
                }
                result = 10*result+(str[i]-'0'); 
            }
            else
            {
                break;
            }
            i++;
        }
        if (is_minus)
        {
            result = -result;
        }

        return result;
    }
};

int main()
{
    Solution s;
    string str = "91283472332";
    cout << s.myAtoi(str) << endl;

    return 0;
}