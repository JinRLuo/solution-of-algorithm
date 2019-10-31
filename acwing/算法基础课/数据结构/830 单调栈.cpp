#include <iostream>
using namespace std;

const int maxn = 100010;
int stk[maxn];
int tt=0;
int n;

int main(){
	int x;
	cin>>n;
	while(n--){
		cin>>x;
		while(tt&&stk[tt-1]>=x){
			tt--;
		}
		if(tt){
			cout << stk[tt-1] << " ";
			stk[tt++]=x;
		}else{
			cout << "-1 ";
			stk[tt++]=x;
		}
	}
} 
