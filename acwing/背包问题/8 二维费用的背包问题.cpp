#include <bits/stdc++.h>
using namespace std;

const int maxn=1005; 
int N,V,M;
int v[maxn],m[maxn],w[maxn];
int f[105][105];

int main(){
	cin>>N>>V>>M;
	for(int i=1;i<=N;i++){
		cin>>v[i]>>m[i]>>w[i];
		for(int j=V;j>=0;j--){
			if(j>=v[i])
				for(int k=M;k>=0;k--){
					if(k>=m[i])
						f[j][k]=max(f[j][k],f[j-v[i]][k-m[i]]+w[i]);
				}
		}
	}
	cout << f[V][M] << endl; 
} 
