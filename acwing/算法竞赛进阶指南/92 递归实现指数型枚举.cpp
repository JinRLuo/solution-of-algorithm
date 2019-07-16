#include <iostream>
using namespace std;

int n;

void dfs(int c,int num){
	if(c==n){
		for(int i=0;i<n;i++){
			if(num&1<<i)
				cout << i+1 << " ";
		}
		cout << endl;
		return;
	}
	dfs(c+1,num);
	dfs(c+1,num|(1<<c));
} 

int main(){
	cin >> n;
	dfs(0,0);
}
