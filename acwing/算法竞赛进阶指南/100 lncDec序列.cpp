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
	ll ans1 = max(p,q);   //��С����������max(������������������) 
	ll ans2 = abs(p-q)+1; //���ܽ��������abs(��������-��������)+1 
	cout << ans1 << endl;
	cout << ans2 << endl;
	
} 
