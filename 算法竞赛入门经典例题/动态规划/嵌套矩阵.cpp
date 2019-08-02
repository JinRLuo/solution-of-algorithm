#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
int g[maxn][maxn];
int t[maxn];
int a[maxn],b[maxn];
int n;

int dp(int i){
	if(t[i]>0)
		return t[i];
	t[i]=1;
	for(int j=0;j<n;j++){
		if(g[i][j]){
		t[i]=max(t[i],dp(j)+1);
		}
	}
	return t[i];
}


int main(){
	int N;
	cin>>N;
	while(N--){
		int res;
		int x,y;
		memset(g,0,sizeof(g));
		memset(t,0,sizeof(t));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			if(x<y)
				swap(x,y);
			a[i]=x;
			b[i]=y;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]>a[j]&&b[i]>b[j]){
					g[i][j]=1;
				}
			}
		}
		res=0;
		for(int i=0;i<n;i++){
			res=max(res,dp(i));
		}
		cout << res << endl;
	}
}
