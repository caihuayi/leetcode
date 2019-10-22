#include <stack>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int mo;
        int result = 0;;
        while(x != 0)
        {
            mo = x%10;
            x /= 10;
            if (result > INT_MAX / 10 || (result == INT_MAX/10 && mo > 7) || result < INT_MIN / 10 || (result == INT_MIN/10 && mo < -8))
                return 0;
            result = result*10 + mo;
        }
        return result;
    }
};
int main()
{
    Solution s;
    //int a = 9646324351;
    //cout << a << endl;
    cout << s.reverse(563847412) << endl;

    return 0;
}