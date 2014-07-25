#include <iostream>
#include <algorithm>
#include <map>
#include <conio.h>

using namespace std;

multimap <int, int> m;
int lowbit(int n){
	int i = -1, ans = 1, mask = 1, stop = 0, j;
	//if (n == 0)
	while(stop != 1){
		i++;
		if((n & (mask << i)) != 0){
			stop = 1;
			for(j = 1; j <= i; j++){
				ans = ans*2;
			}

		}
	}
	return ans;
}
bool cmp(int a, int b){
	return a>b;
}

int main(){
	int sum, limit, i, j, k, ans, zero;
	int arr[100005], l[100005];
	cin >> sum >> limit;
	for(i = 1; i <= limit; i++){
		l[i] = lowbit(i);
	}
	//sort(l+1, l+limit+1, cmp);
	for(i = 1; i <= limit; i++){
         m.insert (make_pair<int,int>(l[i],i) );
	}
	multimap<int,int>::reverse_iterator rit;
  	//for (rit=m.rbegin(); rit!=m.rend(); ++rit)
    //cout << (*rit).first << " => " << (*rit).second << '\n';

	if(limit % 2 == 0)zero = limit / 2;
	else zero = (limit+1) / 2;
	//for(i = 1; i <= limit-zero; i++)cout << l[i] << " d ";
	ans = 0;
	j = 0;
    multimap<int,int>::reverse_iterator it;
  	for (it=m.rbegin(); it!=m.rend(); ++it){
		//cout << "k";
		if(ans + it->first < sum){
			ans += (*it).first;
			arr[j++] = (*it).second;
		}
		else if(ans + (*it).first == sum){
			cout << j+1 << endl;
			for(k = 0; k < j; k++){
				cout << arr[k] << " ";
			}
			cout << (*it).second << endl;
			getch();
			return 0;
		}
	}

	cout << "-1" << endl;
	//cout << lowbit(6);*/
	getch();
	return 0;
}
