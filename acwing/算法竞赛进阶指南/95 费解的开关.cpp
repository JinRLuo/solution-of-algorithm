#include <iostream>
using namespace std;

int t=100;

bool ok(int a[6][6]){
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++){
			if(a[i][j]!=1)
				return false;
		}
	return true;
}

void dfs(int a[6][6],int k){
	if(ok(a)){
		if(k<t)
			t=k;
		return;
	}else if(k>6)
		return;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			a[i][j]^=1;
			a[i-1][j]^=1;
			a[i+1][j]^=1;
			a[i][j-1]^=1;
			a[i][j+1]^=1;
			dfs(a,k+1);
		}
	}
}

int main(){
	int n;
	int arv[6][6]; 
	cin >> n;
	while(n--){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin >> arv[i][j];
		dfs(arv,0);
		if(t==100)
			t=-1;
		cout << t << endl;
		t=100;
	}
}
