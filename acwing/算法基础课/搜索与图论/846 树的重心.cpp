#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int v[maxn],f[maxn];
int n;
int ans=INT_MAX;
int e[2*maxn],ne[2*maxn],idx;

int dfs(int x){
	f[x]=1;
	int cut=1,res=0;
	for(int i=v[x];i!=-1;i=ne[i]){
		if(!f[e[i]]){
			int k = dfs(e[i]);
			cut += k;
			res=max(res,k);
		}
	}
	res=max(res,n-cut);
	ans=min(res,ans);
	return cut;
}

void add(int a,int b){
	e[idx]=b;
	ne[idx]=v[a];
	v[a]=idx++;
}

int main(){
	int a,b;
	memset(v,-1,sizeof(v));
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		add(a,b);
		add(b,a); 
	}
	
	dfs(1);
	
	cout << ans << endl;
	
	return 0;
}
