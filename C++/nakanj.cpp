# include <cstdio>
# include <queue>
using namespace std;
int a,b;
int y1,y2;
int bfs() {
	int ch1,ch2,ch3;
	queue <int> q1;
	queue <int> q2;
	queue <int> q3;
	q1.push(a);
	q2.push(y1);
	q3.push(0);
	while(!q1.empty()) {
		ch1=q1.front();
		ch2=q2.front();
		ch3=q3.front();
		q1.pop();
		q2.pop();
		q3.pop();
		if(ch1==b && ch2==y2)return ch3;
		else if(ch1<1 || ch1>8 || ch2<1 || ch2>8)continue;
		else {
			q1.push(ch1+1);q2.push(ch2+2);q3.push(ch3+1);
			q1.push(ch1+2);q2.push(ch2+1);q3.push(ch3+1);
			q1.push(ch1+2);q2.push(ch2-1);q3.push(ch3+1);
			q1.push(ch1+1);q2.push(ch2-2);q3.push(ch3+1);
			q1.push(ch1-1);q2.push(ch2-2);q3.push(ch3+1);
			q1.push(ch1-2);q2.push(ch2-1);q3.push(ch3+1);
			q1.push(ch1-2);q2.push(ch2+1);q3.push(ch3+1);
			q1.push(ch1-1);q2.push(ch2+2);q3.push(ch3+1);
		}
	}
}
int main() {
	int t,i,ans;
	char x1,x2,ch,Y1,Y2;
	scanf("%d",&t);
	scanf("%c",&ch);
	char s[6];
	char s1[6];
	char chr[]={'a','b','c','d','e','f','g','h'};
	while(t--) {
		scanf("%s %s",s,s1);
		x1=s[0];
		y1=s[1]-'0';
		x2=s1[0];
		y2=s1[1]-'0';
		if(x1==x2 && y1==y2)printf("0\n");
		else {
			for(i=0;i<8;i++) {
				if(x1==chr[i])a=i+1;
				if(x2==chr[i])b=i+1;
				
			}
			ans=bfs();
			printf("%d\n",ans);
		}
	}
	return 0;
}
