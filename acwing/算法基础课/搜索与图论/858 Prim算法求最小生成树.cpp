#include <iostream>
#include <cstring>
using namespace std;

//最小生成树 prim算法
//集合st为生成树的集合
//每次在图中找到与集合距离最短的点(此边就是最小生成树的边)，将其加入集合并更新其他点与集合的距离 
//将上述过程重复n次 

const int N = 510,INF=0x3f3f3f3f;
int g[N][N],dist[N],st[N];
int n,m;

int prim(){
	memset(dist,0x3f,sizeof(dist));
	int res=0;
	for(int i=0;i<n;i++){
		int t=-1;
		for(int j=1;j<=n;j++){
			if(!st[j]&&(t==-1||dist[j]<dist[t]))
				t=j;
		}
		if(i&&dist[t]==INF) return INF;  //如果集合外点与集合的最短距离为INF,说明该点与生成树之间没有边,则没有最小生成树 
		if(i) res+=dist[t];
		
		st[t]=1;
		
		for(int j=1;j<=n;j++){
			if(!st[j])
				dist[j]=min(dist[j],g[t][j]);
		}
	}
	return res;
}

int main(){
	memset(g,0x3f,sizeof(g));
	cin>>n>>m;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b]=g[b][a]=min(g[a][b],c);
	}
	int res = prim();
	if(res==INF) cout << "impossible" << endl;
	else cout << res << endl;
} 
