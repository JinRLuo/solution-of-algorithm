#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll a[100010];

int main(){
	ll sum=0,mid;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	mid=a[n/2];
	for(int i=0;i<n;i++){
		sum+=abs(mid-a[i]);
	}
	cout << sum << endl;
}
