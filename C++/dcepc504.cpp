this question is related to THUE MORSE series.
sequence http://oeis.org/A010060

how to create THUE MORSE series--

a(2n)=a(n)
a(2n+1)=1-a(n)

let for n=0,a(0)=0;



n = 0, substituting in Eq. 1: t1 = 1 - t0 = 1 (t0 is 0)
n = 1, substituting in Eq. 2: t2 = t1 = 1
n = 1, substituting in Eq. 1: t3 = 1 - t2 = 1 - 1 = 0
n = 2, substituting in Eq. 2: t4 = t2 = 1
n = 2, substituting in Eq. 1: t5 = 1 - t4 = 1 - 1 = 0
n = 3, substituting in Eq. 2: t6 = t3 = 0
n = 3, substituting in Eq. 1: t7 = 1 - t6 = 1 - 0 = 1


HERE is the code

#include
int main()
{
    int t,count;
    long long int k,num;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%lld %lld",&k,&num);
        if(num==1)
            printf("Male\n");
        else if(num==2)
            printf("Female\n");
        else{
            num=num-1;
        while(num>1)
        {
            if(num%2!=0)
                count+=1;
            num=num/2;
        }
        if(count%2==0)
            printf("Female\n");
        else
            printf("Male\n");
        }
        printf("\n");
    }
    return 0;
}

