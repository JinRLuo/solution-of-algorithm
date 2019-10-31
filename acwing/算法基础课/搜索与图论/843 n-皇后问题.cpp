#include <iostream>
using namespace std;

int r[10],f[10];
int n;

int judge(int x){
	for(int i=1;i<x;i++){
		if(r[i]==r[x]||(abs(r[i]-r[x])==abs(i-x))){
			return 0;
		}
	}
	return 1;
}

void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(r[i]==j)
					cout << "Q";
				else
					cout << ".";
			}
			cout << endl; 
		}
		cout << endl;
		return;
	}
	for(int i=1;i<=n;i++){
		r[x]=i;
		if(judge(x)){
			dfs(x+1);
		}
	}
}

int main(){
	cin>>n;
	dfs(1);
	return 0;
}
