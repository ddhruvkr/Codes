# include <cstdio>
# include <cstdlib>
# include <string>
# include <cstring>
# include <iostream>
# include <conio.h>
using namespace std;
int main()
{
	int t,Q,i,j,br,q,L,l,m,n;
	char ch,c;
	scanf("%d",&t);
	while(t--) {
		string S;
		string cp;
		char A[100001],B[100001];
		cin >> S;
		scanf("%d",&Q);
		//printf("%d\n",Q);
		while(Q--) {
            //printf("%d\n",Q);
   			scanf("%c%c",&ch,&ch);
			if(ch=='I') {
				scanf("%d",&i);
				cin >> cp;
				S.insert(i,cp);
				//cout << S << '\n';
			}
			else if(ch=='R') {
                scanf("%d",&i);
                cin >> cp;
                S.replace(i-1,1,cp);
                //cout << S << '\n';
			}
			else if(ch=='Q') {
                scanf("%d%d",&i,&j);
                L=S.length();
                //printf("L=%d\n",L);
   				S.copy(A,L-i+1,i-1);
				S.copy(B,L-j+1,j-1);
				m=L-i+1;
				n=L-j+1;
				//printf("m=%d\n",m);
				//printf("n=%d\n",n);
				A[m]='\0';
				B[n]='\0';
				//printf("A= %s\n",A);
				//printf("B= %s\n",B);
				if(m<=n)l=m;
				else l=n;
				//printf("l=%d\n",l);
				br=0;q=0;
				while(br!=1 && q<l) {
					if(A[q]==B[q])q++;
					else br=1;
					//printf("q=%d br=%d\n",q,br);
				}
				printf("%d\n",q);
			}
		}
	}
	getch();
	return 0;
}
