#include <bits/stdc++.h> 
using namespace std;

int N,V;
int v[105],w[105],s[105];
int f[105];

int main(){
	cin>>N>>V;
	for(int i=1;i<=N;i++){
		cin>>v[i]>>w[i]>>s[i];
	}
	for(int i=1;i<=N;i++){
		for(int j=V;j>=0;j--){
			for(int k=0;k<=s[i];k++){
				if(j>=k*v[i])
					f[j]=max(f[j],f[j-k*v[i]]+k*w[i]);
			}
		}
	}
	cout << f[V] << endl;
}
