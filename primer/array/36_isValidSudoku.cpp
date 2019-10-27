#include <vector>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int convertToInt(char c)
    {
        if (c == '.') return -1;
        else return c-'0';
    }

    bool rawValid(vector<char> &arr, set<int> &se)
    {
        se.clear();
        int n;
        for (int i = 0; i < 9; i++)
        {
            n = convertToInt(arr[i]);
            if (n != -1)
            {
                if (se.find(n) == se.end())
                {
                    se.insert(n);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool columnValid(vector<vector<char>> &arr, int column, set<int> &se)
    {
        se.clear();
        int n;
        for (int i = 0; i < 9; i++)
        {
            n = convertToInt(arr[i][column]);
            if (n != -1)
            {
                if (se.find(n) == se.end())
                {
                    se.insert(n);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool rectValid(vector<vector<char>> &arr, int i, int j, set<int> &se)
    {
        se.clear();
        i *= 3;
        j *= 3;
        int n = 0;
        int m = 0;
        while(1)
        {
            while(1)
            {
                m = convertToInt(arr[i][j]);
                if (m != -1)
                {
                    if (se.find(m) == se.end())
                    {
                        se.insert(m);
                        //cout << "m=" << arr[i][j] << i << j << endl;
                    }
                    else
                    {
                        return false;
                    }
                }
                ++j;
                if (++n%3 == 0)
                {
                    break;
                }
            }
            ++i;  
            j -= 3;          
            if (n == 9)
            {
                break;
            }
        }
        //cout << endl;
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool result = true;
        int i = 0;
        set<int> se;
        //cout << "raw: ";
        for (; i < 9; i++)
        {
            result &= rawValid(board[i], se);
            //cout << result << " ";
        }
        cout << endl << "column: "; 
        for (i = 0; i < 9; i++)
        {
            result &= columnValid(board, i, se);
            cout << result << " ";
        }
        //cout << endl << "rect: ";
        for (i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                //cout << "i, j, result: " << i << j << result << " " << endl;
                result &= rectValid(board, i, j, se);
            }
        }
        cout << endl;
        return result;
    }
};

int main()
{
    vector<vector<char>> arr = {
        {'.','.','4','.','.','.','6','3','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','.','9','.'},
        {'.','.','.','5','6','.','.','.','.'},
        {'4','.','3','.','.','.','.','.','1'},
        {'.','.','.','7','.','.','.','.','.'},
        {'.','.','.','5','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'}
        };
    Solution s;
    set<int> se;
    cout << s.isValidSudoku(arr) << endl;;

    return 0;
}