#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100010];
ll f[100010];

int main(){
	ll n,p=0,q=0,count;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i]; 
		f[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		if(f[i]>0)
			p+=f[i];
		else if(f[i]<0)
			q+=abs(f[i]);
	}
	ll ans1 = max(p,q);   //最小操作数等于max(正数个数，负数个数) 
	ll ans2 = abs(p-q)+1; //可能结果数等于abs(正数个数-负数个数)+1 
	cout << ans1 << endl;
	cout << ans2 << endl;
	
} 
