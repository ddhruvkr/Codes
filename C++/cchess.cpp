# include <cstdio>
# include <vector>
using namespace std;
int a,b,c,d;
vector <int> q1;
vector <int> q2;
vector <int> q3;
void djikstra() {
	int i,j;
    bool visited[8][8];
    for(i=0;i<8;i++)for(j=0;j<8;j++)visited[i][j]=false;
	int ch1,ch2,ch3,min=0;
	q1.clear();
	q2.clear();
	q3.clear();
	vector<int>::iterator it;
	vector<int>::iterator it1;
	vector<int>::iterator it2;
	vector<int>::iterator p;
	vector<int>::iterator q;
	vector<int>::iterator r;
	q1.push_back(a);
	q2.push_back(b);
	q3.push_back(0);
	visited[a][b]=true;
	while(!q1.empty()) {
		it=q3.begin();
		min=*it;
		p=it;
		it1=q1.begin();
		it2=q2.begin();
		q=it1;
		r=it2;
		for(it=q3.begin(),it1=q1.begin(),it2=q2.begin();it!=q3.end();it++,it1++,it2++) {
			if(min>*it){min=*it;p=it;q=it1;r=it2;}
		}
		ch1=*q;
		ch2=*r;
		ch3=min;
		visited[ch1][ch2]=true;
		q1.erase(q);
		q2.erase(r);
		q3.erase(p);
		if(ch1==c && ch2==d){printf("%d\n",ch3);return;}
		else {
			if(ch1<7 && ch2<6)
			{
				if(visited[ch1+1][ch2+2]==false) {
				q1.push_back(ch1+1);q2.push_back(ch2+2);q3.push_back(ch3+(ch1*(ch1+1))+(ch2*(ch2+2)));visited[ch1+1][ch2+2]==true;}
			}
			if(ch1<6 && ch2<7)
			{
                if(visited[ch1+2][ch2+1]==false) {
				q1.push_back(ch1+2);q2.push_back(ch2+1);q3.push_back(ch3+(ch1*(ch1+2))+(ch2*(ch2+1)));visited[ch1+2][ch2+1]==true;}
			}
			if(ch1<6 && ch2>0)
			{
                if(visited[ch1+2][ch2-1]==false) {
				q1.push_back(ch1+2);q2.push_back(ch2-1);q3.push_back(ch3+(ch1*(ch1+2))+(ch2*(ch2-1)));visited[ch1+2][ch2-1]==true;}
			}
			if(ch1<7 && ch2>1)
			{
                if(visited[ch1+1][ch2-2]==false) {
				q1.push_back(ch1+1);q2.push_back(ch2-2);q3.push_back(ch3+(ch1*(ch1+1))+(ch2*(ch2-2)));visited[ch1+1][ch2-2]==true;}
			}
			if(ch1>0 && ch2>1)
			{
                if(visited[ch1-1][ch2-2]==false) {
				q1.push_back(ch1-1);q2.push_back(ch2-2);q3.push_back(ch3+(ch1*(ch1-1))+(ch2*(ch2-2)));visited[ch1-1][ch2-2]==true;}
			}
			if(ch1>1 && ch2>0)
			{
                if(visited[ch1-2][ch2-1]==false) {
				q1.push_back(ch1-2);q2.push_back(ch2-1);q3.push_back(ch3+(ch1*(ch1-2))+(ch2*(ch2-1)));visited[ch1-2][ch2-1]==true;}
			}
			if(ch1>1 && ch2<7)
			{
                if(visited[ch1-2][ch2+1]==false) {
				q1.push_back(ch1-2);q2.push_back(ch2+1);q3.push_back(ch3+(ch1*(ch1-2))+(ch2*(ch2+1)));visited[ch1-2][ch2+1]==true;}
			}
			if(ch1>0 && ch2<6)
			{
                if(visited[ch1-1][ch2+2]==false) {
				q1.push_back(ch1-1);q2.push_back(ch2+2);q3.push_back(ch3+(ch1*(ch1-1))+(ch2*(ch2+2)));visited[ch1-1][ch2+2]==true;}
			}
		}
	}
	printf("-1\n");
}
int main() {
	while ( scanf( "%d", &a ) != EOF ) {
		scanf( "%d%d%d", &b, &c, &d );
		if(a==c && b==d)printf("0\n");
		else {
			djikstra();
		}
	}
	return 0;
}
