#include <stdio.h>
#include <string.h>
int is_balanced(int* freq)
{
    int i;
    int count = 0;
    int diff_chars = 0;
    for (i = 0; i < 26; i++)
    {
        if (freq[i] > 0) diff_chars++;
        if (freq[i] == freq[0] && freq[i] > 0) count++;
    }
    if (diff_chars == 2 && count == 2) return 1;
    return 0;
}
int longest_balanced_substring_helper(char* s, int start, int end)
{
    if (end - start + 1 < 2)
    {
        return 0; // substring too short to be balanced
    }
    int freq[26] = {0};
    int i;
    for (i = start; i <= end; i++)
    {
        freq[s[i] - 'a']++;
    }
    if (is_balanced(freq))
    {
        return end - start + 1; // this substring is balanced
    }
    int len1 = longest_balanced_substring_helper(s, start, end - 1);
    int len2 = longest_balanced_substring_helper(s, start + 1, end);
    return (len1 > len2) ? len1 : len2; // return the longer of the two balanced substrings
}
int longest_balanced_substring(char* s)
{
    return longest_balanced_substring_helper(s, 0, strlen(s) - 1);
}
int main()
{
    printf("this code run by Recursive\n");
    printf("---------------------------------------\n");
    char s[25];
    printf("please..Enter your string here:");
    scanf("%s",&s);
    printf("the longest balanced substring for ( %s ) = %d\n",s,longest_balanced_substring(s));
    return 0;
}

