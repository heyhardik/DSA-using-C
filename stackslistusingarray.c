#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE],top=-1;
int isempty(){
    return(top==-1)?1:0;
}
int isfull(){
    return(top==SIZE-1)?1:0;
}
void push(){
    if (isfull()){
        printf("Stack overflow...\n");
    }
    else{
        top++;
        int val;
        printf("Enter Element:");
        scanf("%d",&val);
        stack[top]=val;
        printf("Element added successfully\n");
    }
}
void pop(){
    if(isempty()){
        printf("Stack is empty!!!\n");
    }
    else{
        int val;
        val=stack[top];
        top--;
        printf("%d is removed from the stack\n",val);
    }
}
void peek(){
    if(isempty()){
        printf("stack is empty!!!\n");
    }
    else{
        int val;
        val=stack[top];
        printf("%d is at top of the stack\n",val);
    }
}
void show(){
    if(isempty()){
        printf("Stack is empty!!!\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
int main(){
    while(1){
        system("cls");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Show\n");
        printf("5.Exit\n");
        int choice;
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            show();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Invalid Choice!!!!");
        }
        system("pause");
    }
     return 0;
}
   
