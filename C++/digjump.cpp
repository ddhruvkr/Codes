#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

int main(){
	int i, j, min, k;
	char s[100005];
	int a[100005], val[100005], m[10];
	for(i = 0; i < 10; i++){
		m[i] = 9999999;
	}
	cin >> s;
	int len = strlen(s);
	
	for(i = 0; i < len; i++){
		a[i] = s[i] - '0';
	}
	m[a[len-1]] = 0;
	val[len-1] = 0;
	for(i = len-2; i >=0; i--){

		min = val[i+1];
		if(m[a[i]] <= min)
		val[i] = m[a[i]]+1;
		else {
			val[i] = min+1;
			m[a[i]] = min+1;
		}
	}
	//for(i = 0; i < len; i++)cout << val[i] << " ";
	//cout << endl;
	
	
	    for(i = 1; i < len-1; i++){

			min = val[i-1]+1;
			if(m[a[i]]+1 < min){
				if(m[a[i]]+1 < val[i])val[i] = m[a[i]]+1;
			}
			else if(val[i] > min)
			val[i] = min;
			if(m[a[i]] > min)
			m[a[i]]= min;
		}
		//for(i = 0; i < len; i++)cout << val[i] << " ";
		//cout << endl;

		//for(i = 0; i < 10; i++)cout << m[i] << endl;
		for(i = len-2; i >=0; i--){

			min = val[i+1];
			if(m[a[i]] <= min)
			val[i] = m[a[i]]+1;
			else {
				val[i] = min+1;
				m[a[i]] = min+1;
			}
		}

	//for(i = 0; i < len; i++)cout << val[i] << " ";
	//cout << endl;
	cout << val[0] << endl;
	getch();
	return 0;
}
