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
                                          else if(words[0].compare("damaged")==0){
                                                                             printf("Normal\n");

                                                                             }
                                          else if(words.size() == 2 && words[0].compare("of") == 0){
                                                          printf("Rare\n");

                                                          }
                                          else if(words.size() == 2){
                                                          printf("Not sure, take anyways\n");

                                                          }
                                        else if(words.size() == 3 || words.size() == 4){
                                                        if(words[words.size()-2].compare("of") == 0){
                                                        printf("Magic\n");

                                                        }
                                                        else {
                                                             printf("Normal\n");

                                                             }
                                                        }
                                        else if(words.size() <2 || words.size()>4){
                                                        printf("Normal\n");

                                                             }

               }
     return 0;
     }
