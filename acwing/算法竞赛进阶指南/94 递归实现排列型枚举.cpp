#include <iostream>
using namespace std;

int n;
int p[10];
bool v[10];

void dfs(int k){
	if(k>n){
		for(int i=1;i<=n;i++){
			cout << p[i] << " ";
		}
		cout << endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=true;
			p[k]=i;
			dfs(k+1);
			v[i]=false;
		}
	}
}

int main(){
	cin >> n;
	dfs(1);
//	for(int i=0;i<=n;i++)
//		cout << p[i] << " ";
//	cout << endl;
}
