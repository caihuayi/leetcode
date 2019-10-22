#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
/*
    bool isback(string &s, int lo, int hi)
    {
        if (lo == hi || (hi - lo == 1 && s[hi] == s[lo] ))
        {

            return true;
        }
        if (s[lo] == s[hi])
        {

            return isback(s, lo+1, hi-1);
        }
        else
        {
            return false;
        }
    }
    
    string longestPalindrome(string s) 
    {
        if (s == "") return "";
        int lo, hi, len = 0;
        int length = s.length();
        for (int i = 0; i < length; i++)
        {
            for (int j = i; j < length; j++)
            {
                if (s[i] == s[j])
                {
                    if (isback(s, i, j) == true)
                    {
                        if (j-i+1 > len)
                        {
                            len = j-i+1;
                            hi = j;
                            lo = i;
                        }
                    }
                }
            }
        }
        string s2(s, lo, hi-lo+1);
        return s2;
    }*/
    int back_length1(string& s, int mid)
    {
        int lo = mid;
        int hi = mid;
        while (lo >= 0 && hi < s.length())
        {
            if (s[lo] == s[hi])
            {
                --lo;
                ++hi;
            }
            else
            {
                return hi-lo-1;
            }
        }
        return hi-lo-1;
    }

    int back_length2(string&s, int mid1, int mid2)
    {
        int lo = mid1;
        int hi = mid2;
        while (lo >= 0 && hi < s.length())
        {
            //cout << "lo: " << lo << " " << "hi: " << hi << endl;
            if (s[lo] == s[hi])
            {
                --lo;
                ++hi;
            }
            else
            {
                return hi-lo-1;
            }
        }
        return hi-lo-1;
    }

    string longestPalindrome(string s) 
    {
        if (s == "") return "";
        if (s.length() == 1) return s;
        int i = 0;
        int max = 0;
        int lo, hi;
        int n;
        for (i = 0; i < s.length()-1; i++)
        {
            n = back_length2(s, i, i+1);
            if (n > max)
            {
                max = n;
                lo = i-max/2+1;
            }
            n = back_length1(s, i);
            if (n > max)
            {
                max = n;
                lo = i-max/2;
            }
        }
        string s2(s, lo, max);
        return s2;
    }
};


int main()
{
    Solution solution;
    string s = "asldbsbsbsl";
    cout << endl << solution.longestPalindrome(s) << endl;

    return 0;
}