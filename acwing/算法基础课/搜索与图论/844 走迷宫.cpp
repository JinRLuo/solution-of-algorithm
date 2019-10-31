#include <iostream>
#include <queue>
#define PII pair<int,int> 
using namespace std;

const int maxn=100;
int v[maxn][maxn],f[maxn][maxn];
int n,m; 
queue<PII> q;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

int bfs(){
	while(!q.empty()){
		PII p = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int x = p.first+dx[i];
			int y = p.second+dy[i];
			if(!f[x][y]&&x>=0&&y>=0&&x<n&&y<m){
				q.push({x,y});
				v[x][y]=v[p.first][p.second]+1;
				f[x][y]=1;
			}
		}
	}
	return v[n-1][m-1];
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>f[i][j];
	
	q.push({0,0});
	f[0][0]=1;
	v[0][0]=0;
	cout << bfs() << endl;
} 
