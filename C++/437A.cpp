#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int index, n, i, j, m;
	int l[4];
	char a[4][110];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	l[0] = strlen(a[0])-2;
	l[1] = strlen(a[1])-2;
	l[2] = strlen(a[2])-2;
	l[3] = strlen(a[3])-2;
	int count[4] = {0};
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(i != j){
				if(l[i] >= 2*l[j])count[i]++;
			}
		}
	}
	n = 0;
	for(i = 0; i < 4; i++){
		if(count[i] == 3){
			n++;
			index = i;
		}
	}
	
    int count1[4] = {0};
    for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(i != j){
				if(2*l[i] <= l[j])count1[i]++;
			}
		}
	}
	m = 0;
	for(i = 0; i < 4; i++){
		if(count1[i] == 3){
			m++;
			index = i;
		}
	}
	if(n+m > 1 || n+m == 0){
        cout << "C" << endl;
		return 0;
	}
	if(m == 1){
		if(index == 0)cout << "A" << endl;
		else if(index == 1)cout << "B" << endl;
		else if(index == 2)cout << "C" << endl;
		else if(index == 3)cout << "D" << endl;
		return 0;
	}
	if(n == 1){
		if(index == 0)cout << "A" << endl;
		else if(index == 1)cout << "B" << endl;
		else if(index == 2)cout << "C" << endl;
		else if(index == 3)cout << "D" << endl;
		return 0;
	}
}
