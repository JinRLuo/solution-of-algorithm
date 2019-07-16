#include <iostream>
using namespace std;
int main(){
	long long a,b,p,res;
	cin >> a >> b >> p;
	res = 0;
	while(b){
		if(b&1){
			res = (res + a)%p;
		}
		a=(a*2)%p;
		b>>=1; 
	}
	cout << res << endl;
}
