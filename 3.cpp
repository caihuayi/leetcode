#include <vector>
#include <string>
#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int start = 0;
    int end = 0;
    int max = 0;
    int size = s.size();
    int i;
    for (end = 0; end < size; end++)
    {
        for (i = start; i < end; i++)
        {
            if (s[i] == s[end])
            {
               start = i + 1;
               break;
            }
        }
        max = (end - start + 1) > max ? end - start + 1 : max;
    }
    return max;
}

int main()
{
    cout << lengthOfLongestSubstring(string("pwwkew")) << endl;

    return 0;
}