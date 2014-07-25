#include<stdio.h>
int main()
{
    char arr[]="abc";
    char *ptr;
    ptr=arr;
    while(*ptr!='\0')
    {
        printf("%c",*ptr);
        printf("\n");
        ptr++;
    }
    printf("\n");
    system("pause");
    return 0;
}
    
    
