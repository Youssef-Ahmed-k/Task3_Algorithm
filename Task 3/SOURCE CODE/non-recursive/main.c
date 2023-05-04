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
    char s[25];
    printf("please..Enter your string here:");
    scanf("%s",&s);
    printf("the longest balanced substring for ( %s ) = %d\n",s,longest_balanced_substring(s));
    return 0;
}

