#include <iostream>
#include <cstring>
using namespace std;

// dijkstra朴素做法  适用于稠密图
// 时间复杂度O(n^2) 

const int maxn = 510;
int g[maxn][maxn];//邻接矩阵 
int dist[maxn];   //源点到各点的最短路径 
int st[maxn];     //红点集 
int n,m; 

int dijkstra(){
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	                                 //最短路其实就是在重复下面这个过程，直到所有的点都加入集合 
	for(int i=0;i<n;i++){            //从不是st集合的点中选一个路径最短的点 
		int t=-1;
		for(int j=1;j<=n;j++){
			if(!st[j]&&(t==-1||dist[j]<dist[t]))
				t=j;
		}
		
		st[t]=1;                     //将这个点加入集合 
		
		for(int j=1;j<=n;j++){       //更行所有点的最短路径 
			dist[j]=min(dist[j],dist[t]+g[t][j]);
		}
	}
	
	if(dist[n]==0x3f3f3f3f)
		return -1;
	else
		return dist[n];
	
}

int main(){
	memset(g,0x3f,sizeof(g));
	int x,y,z;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> x >> y >> z;
		g[x][y]=min(g[x][y],z);
	}
	
	int res = dijkstra();
	
	cout << res << endl;;
	
	return 0;
} 
