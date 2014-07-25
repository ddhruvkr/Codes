# include <stdio.h>
# include <stdlib.h>
int main() {
	int count = 0, t, n;
	long long d, s, str;
	scanf("%d" , &t);
	while(t--) {
		s = 1;
		str = 1;
		count++;
		scanf("%d" , &n);
		while(n--) {
        	scanf("%lld" , &d);
        	if(d >= 0)
			s = s + d;
			else {
				if(abs(d) >= s) {
					if(abs(d) - s >= 0)str = str + abs(d) - s + 1;
					s = 1;
				}
			}
		}
		printf("Scenario #%d: %lld\n" , count , str);
	}
	return 0;
}



int main()
{
    int t,i,count=1;
    scanf("%d",&t);
    while(t--)
    {
        long long int num,sum=0,coke=0;
        scanf("%lld",&num);
        long long int arr[num];
        for(i=0;i<num;i++)
        {
            scanf("%lld",&arr[i]);
            sum+=arr[i];
            if(sum<0)
            {
                coke+=fabs(sum);
                sum=0;
            }
        }

        printf("Scenario #%d: %lld\n",count,coke+1);
        count+=1;

    }
    return 0;
}

