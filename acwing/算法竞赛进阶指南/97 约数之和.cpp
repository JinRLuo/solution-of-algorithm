#include <bits/stdc++.h>
#define ll long long
#define mod 9901
using namespace std;

ll quick(ll a,ll b){
	ll res=1;
	a%=mod;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

ll sum(ll a,ll b){
	if(b==0){
		return 1;
	}
	if(b%2==0){
		return ((1+quick(a,b/2))*sum(a,b/2-1)+quick(a,b))%mod;
	}else
		return ((1+quick(a,(b+1)/2))*sum(a,(b-1)/2))%mod;
}

int main(){
	ios::sync_with_stdio(false);
	ll a,b,s=1,k;
	cin >> a >> b;
	for(int i=2;i<=a;i++){
		k=0;
		while(a%i==0){
			k++;
			a/=i;
		}
		s=s*sum(i,k*b)%mod;
	}
	if(a==0)
		cout << 0 << endl;
	else
		cout << s%mod << endl;
}


