#include <stdio.h>
#include <string.h>
int main()
{
    char str[100], stack[100];
    int top = -1, i, len;
    printf("Enter Expression :");
    gets(str);
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            top++;
            stack[top] = str[i];
        }
        else if (str[i] == ']' || str[i] == '}' || str[i] == ')')
        {
            char ch = stack[top];
            if (ch == '[')
                ch = ']';
            else if (ch == '{')
                ch = '}';
            else
                ch = ')';
            if (ch == str[i])
            {
                top--;
            }
            else
                break;
        }
    }
    if (top == -1)
        printf("Balanced...");
    else
        printf("Not Balanced!!!!");
    return 0;
}