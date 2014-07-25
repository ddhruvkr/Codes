/*treat capital letter as '1' and small letters as'0' and create a binary representation of input string .
for e.g
given string is "AaaaBbB"
then binary representation is -- 1000101(arr1)
now there is two way to generate alternating chain
1st one is 0101010(arr2)
2nd one is 1010101(arr3)
now compare this two alternating chains with the arr1(generated acc, to input string )
now find the bit difference of arr1 with arr2 and arr3.
let say the bit diff. of arr1 and arr2 is count1 and the bit differnce of arr1 and arr3 is count3
now find minimum of count1 and count2
print that value .
Question solved :)



SOURCE CODE--*/




#include <cstdio>
#include <cstrlib>


int main()
{
    char str[1005];
    int len,i,count1,a,count2;
    while(scanf("%s",str)!=EOF)
    {
        len=strlen(str);
        int arr1[len];
        int arr2[len];
        int arr3[len];
        count1=0,count2=0;
        if(len==1)
            printf("0\n");
        else
        {
            for(i=0;i<len;i++)
            {
                a=str[i];
               // printf("%d ",a);
                if(a>=65&&a<=90)
                    arr1[i]=1;
                else
                    arr1[i]=0;
            }

            a=str[0];
            if(a>=65&&a<=90){
                arr2[0]=1;
                arr3[0]=0;
            }
            else{
                arr2[0]=0;
                arr3[0]=1;
            }
            for(i=1;i<len;i++)
            {
                if(arr2[i-1]==0)
                {
                    arr2[i]=1;
                    arr3[i]=0;
                }
                else{
                    arr2[i]=0;
                    arr3[i]=1;
                }
            }
            /*for(i=0;i
                printf("%d ",arr1[i]);
            printf("\n");
            for(i=0;i
                printf("%d ",arr2[i]);*/
            for(i=0;i<len;i++)
            {
                if(arr1[i]!=arr2[i])
                    count1+=1;
                if(arr1[i]!=arr3[i])
                    count2+=1;
            }
            printf("%d\n",(count1<count2)?count1:count2);
        }
    }
    return 0;
}
