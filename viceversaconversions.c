#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int precedence(char op){
    switch(op){
        case'+':
        case'-':
        return 1;
        case'*':
        case'/':
        return 2;
        default:
        return 0;
    }
}
char *PostFixToInfix(char *exp)
{
		int len = strlen(exp);
		char *res = (char *)malloc(len + 1);
		char tmp[128][128] = { 0 };
		int ti = -1;

		for (int i = 0; i < len; i++) {
				char c = exp[i];
				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
						ti++;
						tmp[ti][0] = c;
						tmp[ti][1] = '\0';
				} else {
						char op2[128];
						strcpy(op2, tmp[ti--]);
						char op1[128];
						strcpy(op1, tmp[ti--]);
						sprintf(tmp[++ti], "(%s%c%s)", op1, c, op2);
				}
		}
		strcpy(res, tmp[0]);
		return res;
}
char *PrefixToInfix(char *exp)
{
		int len = strlen(exp);
		char *res = (char *)malloc(len + 1);
		char tmp[128][128] = { 0 };
		int ti = -1;

		for (int i = len - 1; i >= 0; i--) {
				char c = exp[i];
				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
						ti++;
						tmp[ti][0] = c;
						tmp[ti][1] = '\0';
				} else {
						char op1[128];
						strcpy(op1, tmp[ti--]);
						char op2[128];
						strcpy(op2, tmp[ti--]);
						sprintf(tmp[++ti], "(%s%c%s)", op1, c, op2);
				}
		}

		strcpy(res, tmp[0]);
		return res;
}
int main(){
    char str[100];
    printf("Enter Postfix Expression: ");
		scanf("\n%[^\n]100s", str);

		int res = PostFixToInfix(str);
		printf("Infix: %s\n", res);
		free(res);
       printf("Enter Prefix Expression: ");
		scanf("\n%[^\n]100s", str);

		res = PrefixToInfix(str);
		printf("Infix: %s\n", res);
		free(res);
		return 0;
}