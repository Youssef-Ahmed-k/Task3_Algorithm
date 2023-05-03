#include <stdio.h>
#include <string.h>
int is_balanced(char* substr)
{
    int count[2] = {0};
    for(int i = 0; i < strlen(substr); i++)
    {
        if(substr[i] == substr[0])
            count[0]++;
        else
            count[1]++;
    }
    return (count[0] == count[1]);
}
int longest_balanced_substring(char* s)
{
    int n = strlen(s);
    int max_length = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+2; j <= n; j++)
        {
            char substr[j-i];
            strncpy(substr, &s[i], j-i);
            substr[j-i] = '\0';
            if(is_balanced(substr) && strlen(substr) > max_length)
                max_length = strlen(substr);
        }
    }
    return max_length;
}
int main()
{
    printf("this code run by non-recursive\n");
    printf("---------------------------------------\n");
    char s1[] = "cabbacc";
    printf("the longest balanced substring for ( %s ) = %d\n",s1,longest_balanced_substring(s1));  // Expected Output: 4

    char s2[] = "abababa";
    printf("the longest balanced substring for ( %s ) = %d\n",s2,longest_balanced_substring(s2));  // Expected Output: 6

    char s3[] = "aaaaaaa";
    printf("the longest balanced substring for ( %s ) = %d\n",s3,longest_balanced_substring(s3));  // Expected Output: 0

    return 0;
}
