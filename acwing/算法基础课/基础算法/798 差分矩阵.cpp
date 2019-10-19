#include <iostream>
using namespace std;

const int maxn = 1005;
int n,m,q;
int a[maxn][maxn];
int b[maxn][maxn];

void cal(int x1,int y1,int x2,int y2,int c){
	a[x1][y1]+=c;
	a[x1][y2+1]-=c;
	a[x2+1][y1]-=c;
	a[x2+1][y2+1]+=c;
}

int main(){
	int x1,y1,x2,y2,c; 
	int x;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			cal(i,j,i,j,x);
		}
	}
	
	for(int i=0;i<q;i++){
		cin>>x1>>y1>>x2>>y2>>c;
		cal(x1,y1,x2,y2,c);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=a[i-1][j]+a[i][j-1]+a[i][j]-a[i-1][j-1];
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
