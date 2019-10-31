#include <iostream>
#include <cstring>
using namespace std;

// 最短路径bellman_ford算法 适用于带有负权边图以及限制最短路最大边数的题目 

const int maxn = 510, maxm = 10010;
int dist[maxn],backup[maxn];
int n,m,k;

struct Edge{    // 对边的存储要求不大，只要能遍历所有边即可 
	int a,b,c;  // 所以此处用结构体存储边 
}edges[maxm];

int bellman_ford(){
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0; 
	for(int i=0;i<k;i++){
		memcpy(backup,dist,sizeof(dist));   // 每次遍历所有边之前对dist数组做备份 
		for(int j=0;j<m;j++){				 
			int a=edges[j].a,b=edges[j].b,c=edges[j].c;
			if(dist[b]>backup[a]+c)
				dist[b]=backup[a]+c;
		}
	}
	
	if(dist[n] > 0x3f3f3f3f/2) return -1;
	else return dist[n];
}

int main(){
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		cin >> edges[i].a >> edges[i].b >> edges[i].c;
	}
	
	int res = bellman_ford();
	if(res==-1) cout << "impossible" << endl;
	else cout << res << endl;
} 
