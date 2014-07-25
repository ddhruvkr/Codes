# include <cstdio>
# include <cstring>
using namespace std;
int main()
{
	int n,i,space,q,r,w,d,e,j,k,ss;
	char a[101];
	char c[101];
	scanf("%d",&n);
	k=n;
	while(n--) {
		gets(a);
		if(n==k-1)gets(a);
		q=0;space=0;
		w=0;e=0;r=0;d=0;
		for(i=0;i<strlen(a);i++) {
			if(a[i]==' ')i=strlen(a);
			else if(a[i]=='\'' && a[i+1]=='s' && a[i+2]=='\0' || a[i]=='\'' && a[i+1]=='s' && a[i+2]==' '){printf("Set\n");q=1;}
			else if(a[i]=='\'' && a[i+1]=='S' && a[i+2]=='\0' || a[i]=='\'' && a[i+1]=='S' && a[i+2]==' '){printf("Set\n");q=1;}
		}
		if(q!=1) {
			for(i=0;i<strlen(a);i++) {
				if(a[i]==' ' || a[i]=='\0') {
					for(j=0;j<i;j++)c[j]=a[j];
					c[j]='\0';
					if(strcasecmp("Damaged",c)==0){printf("Normal\n");w=1;}
					i=strlen(a);
				}
			}
		}
		if(q!=1 && w!=1)
		for(i=0;i<strlen(a);i++)if(a[i]==' ')space++;
		
		if(q!=1 && w!=1 && space==1) {
			for(i=0;i<strlen(a);i++) {
				if(a[i]==' '){c[i]='\0';i=strlen(a);if(strcasecmp(c,"of")==0){printf("Rare\n");d=1;}}
				else {c[i]=a[i];}
			}
	   }
	   
	   if(q!=1 && w!=1 && d!=1 && space==1) {
			printf("Not sure, take anyways\n");r=1;
		}
		
		if(q!=1 && w!=1 && space>=2 && space <=3) {
			for(i=strlen(a)-1;i>=0;i--) {
				if(a[i]==' '){c[0]=a[i-2];c[1]=a[i-1];c[2]='\0';if(strcasecmp(c,"of")==0){printf("Magic\n");e=1;}
				}
			}
		}
		
		if(q!=1 && w!=1 && e!=1 && r!=1 && d!=1)printf("Normal\n");
	}
	return 0;
}









/*
#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
    char str[200];
    int t,start;
    scanf("%d", &t);
    while(t--){
               vector<string> words;
               scanf(" %[^\n]",str);
               int i=0;
               while(str[i] != '\n' && str[i] != '\0'){
                    start = i;
                    while(str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
                            i++;
                    string s(&str[start],i-start);
                    words.push_back(s);
                    if(str[i]== ' ') i++;
                }
               for(i=0;words.size()>0 && i<words[0].length();i++)
                    if(words[0][i] >=65 && words[0][i] <=90)
                        words[0][i]=words[0][i]+'a'-'A';
               for(i=0;words.size()>2 && i<words[words.size()-2].length();i++)
                    if(words[words.size()-2][i] >=65 && words[words.size()-2][i] <=90)
                        words[words.size()-2][i]=words[words.size()-2][i]+'a'-'A';

                                          //cout<<words[i]<<' '<<words[i].length()<<endl;
                if(words[0][words[0].length()-2] == '\'' && (words[0][words[0].length()-1]== 's' || words[0][words[0].length()-1]== 'S')){
                        printf("Set\n");
				}
                else if(words[0].compare("damaged")==0)
                    printf("Normal\n");
                    
                else if(words.size() == 2 && words[0].compare("of") == 0)
                    printf("Rare\n");

                else if(words.size() == 2)
                    printf("Not sure, take anyways\n");

                else if(words.size() == 3 || words.size() == 4){
                    if(words[words.size()-2].compare("of") == 0){
                        printf("Magic\n");
				     }
                    else {
                        printf("Normal\n");
                        }
                }
                else if(words.size() <2 || words.size()>4)
                    printf("Normal\n");

        }
     return 0;
}*/
