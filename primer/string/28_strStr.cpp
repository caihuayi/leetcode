#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int n;
        for (n = 0; n < needle.size(); n++)
        {
            if (haystack[n] != needle[n])
            {
                break;
            }
        }
        if (n == needle.size())
        {
            return 0;
        }
        int *next = getNext(needle);
        int needle_size = needle.size();
        int i = 0, j = -1;
        while (i < haystack.size() && j < needle_size)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == needle_size)
        {
            return i-j;
        }
        else
        {
            return -1;
        }
        
    }

    int *getNext(string needle)
    {
        int *next = new int[needle.size()];
        next[0] = -1;
        int i = 0, j = -1;
        while (i < needle.size()-1)
        {
            if (j == -1 || needle[i] == needle[j])
            {
                i++;
                j++;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }


        return next;
    }
};

int main()
{
    Solution s;
    string haystack = "a";
    string needle = "a";
    
    cout << s.strStr(haystack, needle) << endl;

    return 0;
}