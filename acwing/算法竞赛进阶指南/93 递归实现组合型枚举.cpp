#include <iostream>
using namespace std;

int n,m;
int p[25];

void dfs(int k){
	if(p[0]==m){
		for(int i=1;i<=m;i++){
			cout << p[i] << " ";
		}
		cout << endl;
		return;
	}
	for(int i=k;i<=n;i++){
		p[++p[0]]=i;
		dfs(i+1);
		p[p[0]--]=0;
	}
} 

int main(){
	cin >> n >> m;
	dfs(1);
}
