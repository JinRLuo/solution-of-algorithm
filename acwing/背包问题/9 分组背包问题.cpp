#include <bits/stdc++.h>
using namespace std;

struct book{
	int v,w;
}b[105][105];

int N,V,S;
int cnt[105];
int f[105];


int main(){
	cin>>N>>V;
	for(int i=1;i<=N;i++){
		cin>>cnt[i];
		for(int j=1;j<=cnt[i];j++){
			cin>>b[i][j].v>>b[i][j].w;
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=V;j>=0;j--){
			for(int k=1;k<=cnt[i];k++){
				if(j>=b[i][k].v)
					f[j]=max(f[j],f[j-b[i][k].v]+b[i][k].w); 
			}
		}
	}
	cout << f[V] << endl;
}
