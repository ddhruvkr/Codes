#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

char input[2002];


int main()
{
        scanf("%s",input);
        int count=1;
        while(input[0]!='-')
        {
                stack<char> s;
                int ans=0;
                int length=strlen(input);
                for(int i=0;i<length;++i)
                {
                        if(input[i]=='{'){ s.push(input[i]); }
                        else
                        {
                                if(!s.empty()){ s.pop(); }
                                else
                                {
                                        ans += 1;
                                        s.push('{');
                                }
                        }
                }
                if(!s.empty())
                {
                        ans += s.size()/2;
                }
                printf("%d. %d\n",count++,ans);
                scanf("%s",input);
        }
        return 0;
}
