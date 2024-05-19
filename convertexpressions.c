#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int precedence(char op){
    switch(op){
    case '+':
    case '-':
    return 1;
    case '*':
    case '/':
    return 2;
    default:
        return 0;
    }
}
char* ConvertInfixToPostfix(char *str){
    int i,x=0,top=-1;
    char operator[100];
    char* s=(char*)malloc(strlen(str)+1);
    for(i=0;str[i]!='\0';i++){
        char ch=str[i];
        if((ch>=48 && ch<=57)||(ch>=65 && ch<=90)||(ch>=97 && ch <=122)){
            s[x++]=ch;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
                if(top==-1)
                operator[++top]=ch;
                else{
                    while(top!=-1 && precedence(ch)<=precedence(operator[top])){
                        s[x++]=operator[top--];
                    }
                    operator[++top]=ch;
                }
            }
            else if(ch=='('){
                operator[++top]=ch;
            }
            else if(ch==')'){
                while(operator[top]!='('){
                    s[x++]==operator[top--];
                }
                top--;
            }
        }
        while(top!=-1){
            s[x++]==operator[top--];
        }
        s[x]='\0';
        return s;
    }
char* ConvertInfixToPrefix(char *str){
    int i,top=-1,x=0;
    char operator[50];
    char* s=(char*)malloc(strlen(str)+1);
    for(i=strlen(str-1);i>=0;i--){
        char ch=str[i];
        if(ch>=48 && ch<=57 || ch>=65 && ch<=90 || ch>=97 && ch<=122){
            s[x++]=ch;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            if(top==-1){
                operator[top++]=ch;
            }
            else{
                while(top!=-1 && precedence(ch)<=precedence(operator[top])){
                    s[x++]=operator[top--];
                }
                operator[top++]=ch;
            }
        }
        else if(ch=='('){
            operator[top]=ch;
        }
        else if(ch==')'){
            while(operator[top]=='('){
                s[x++]==operator[top--];
            }
            top--;
        }
        while(top!=-1){
            s[x++]=operator[top--];
        }
    }
    s[x]='\0';
    return strrev(s);
}
int main(){
    char str[100];
    printf("Enter expression:");
    gets(str);
    printf("postfix form of infix expression %s is %s\n",str,ConvertInfixToPostfix(str));
    printf("prefix form of infix expression %s is %s",str,ConvertInfixToPrefix(str));
}