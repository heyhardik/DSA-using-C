#include <stdio.h>
#include <stdlib.h>
#define maxsize 1000
int size,list[maxsize];
void Create()
{
    printf("Enter the size Of List:");
    scanf("%d", &size);
    if (size > maxsize)
        printf("List Overflow!!!\n");
    else
    {
        printf("enter List elements:\n");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &list[i]);
        }
    }
}
void Insert()
{
    int pos, value;
    printf("enter Position where You Want To Insert The Element:");
    scanf("%d", &pos);
    printf("Enter The Value To Insert:");
    scanf("%d", &value);
    if (pos < size)
    {
        for (int i = size; i >= pos; i--)
            list[i] = list[i - 1];
        list[pos] = value;
        size++;
    }
    else
        printf("Invalid Position!!!\n");
}
void Display()
{
    if (size == 0)
    {
        printf("List is Empty!!!");
    }
    else
    {
        printf("List Elements are:\n");
        for (int i = 0; i < size; i++)
            printf("%d\t", list[i]);
    }
}
void Delete()
{
    if (size == 0)
    {
        printf("List Is Empty!!!\n");
    }
    else
    {
        int pos;
        printf("Enter Position:\n");
        scanf("%d", &pos);
        if (pos > 0 && pos <= size)
        {
            for (int i = pos - 1; i < size; i++)
                list[i] = list[i + 1];
            size--;
            printf("Element Deleted!!!\n");
        }
        else
            printf("Invalid Position!!!\n");
    }
}
void Search()
{
    if (size == 0)
    {
        printf("List Is empty!!!\n");
    }
    else
    {
        int val, i;
        printf("Enter The Value to Search:\n");
        scanf("%d", &val);
        for (i = 0; i < size; i++)
            if (list[i] == val)
            {
                break;
            }
        if (i == size)
            printf("Element Not Found!!!\n");
        else
            printf("element Founded!!!\n");
    }
}
void main()
{
    Create();
    Insert();
    Display();
    Delete();
    Display();
    Search();
}
//     while (1)
//     {
//         system("cls");
//         printf("1. Create List:\n");
//         printf("2. Insert Element in List:\n");
//         printf("3. Display List:\n");
//         printf("4. Delete Element from the List:\n");
//         printf("5. Search Element In  List:\n");
//         printf("6. Exit:\n");
//         int choice;
//         printf("Enter choice:\n");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             Create();
//             break;
//         case 2:
//             Insert();
//             break;
//         case 3:
//             Display();
//             break;
//         case 4:
//             Delete();
//             break;
//         case 5:
//             Search();
//             break;
//         case 6:
//             exit(0);
//             break;
//         default:
//             printf("Invalid Choice!!!\n");
//         }
//         system("pause");
//     }
// }