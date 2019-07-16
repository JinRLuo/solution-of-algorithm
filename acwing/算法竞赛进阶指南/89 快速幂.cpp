#include <iostream>
using namespace std;
int main(){
	long long a,b,p,res;
	cin >> a >> b >> p;
	res=1%p;
	a=a%p;
	while(b){
		if(b&1){
			res = (res*a)%p;
		}
		a=a*a%p;
		b>>=1;
	}
	cout << res << endl; 
} 
