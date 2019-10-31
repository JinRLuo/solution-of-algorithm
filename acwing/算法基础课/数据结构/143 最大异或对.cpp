#include <iostream>
using namespace std;

const int maxn = 100010;
const int maxm = 31*maxn;
int a[maxn];
int n;
int son[maxm][2];
int idx;
int cnt[maxm];

void insert(int t){
	int p=0;
	for(int i=30;i>=0;i--){
		int u=(t>>i)&1;
		if(!son[p][u]) son[p][u]=++idx;
		p=son[p][u];
	}
	cnt[p]=t;
	//cout << "p:" << t << endl;
}

int search(int t){
	int p=0;
	for(int i=30;i>=0;i--){
		int u=(t>>i)&1;
		if(u==1){
			if(son[p][0]){
				p=son[p][0];
			}else
				p=son[p][1];
		}else{
			if(son[p][1])
				p=son[p][1];
			else
				p=son[p][0];
		}
	}
	//cout << "cnt:p" << cnt[p] << " " << p << endl;
	return t^cnt[p];
}

int main(){
	int res=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		insert(a[i]);
		res=max(search(a[i]),res);
	}
	cout << res << endl;
}
