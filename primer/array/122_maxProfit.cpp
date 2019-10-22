#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int j = 0;
        int profit = 0;
        int minus;
        while(j < prices.size()-1)
        {
            minus = prices[j++] - prices[j];
            if (minus < 0) profit -= minus;

        }

        return profit;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {7,1,5,3,6,4};
    cout << s.maxProfit(arr) << endl;

    return 0;
}