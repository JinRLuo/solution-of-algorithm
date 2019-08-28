#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1005;
int n,m,q;
int x1,y1,x2,y2;
int a[maxn][maxn];

int main(){
	int t;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>t;
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+t;
		}
	}
	for(int i=0;i<q;i++){
		cin>>x1>>y1>>x2>>y2;
		cout << a[x2][y2]+a[x1-1][y1-1]-a[x2][y1-1]-a[x1-1][y2] << endl;
	}
	return 0;
}
