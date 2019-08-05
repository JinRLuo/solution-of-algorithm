#include <bits/stdc++.h>
using namespace std;

int n;
int a[10000];
int dp[10000];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		dp[i]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i])
				dp[i]=max(dp[i],dp[j]+1);
		}
	}
	int res=0;
	for(int i=0;i<n;i++){
		res=max(res,dp[i]);
	}
	cout << res << endl;
}
