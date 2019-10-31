#include <iostream>
#include <cstring>
#include <queue>
#define PII pair<int,int>
using namespace std;

//Dijkstra堆优化版 适用于稀疏图 

const int maxn = 100010;

int h[maxn],w[maxn],e[maxn],ne[maxn],idx; // 邻接表存储  w数组存储边权 
int dist[maxn],st[maxn];                  // 最短路径和标记数组  st表示已经求出最短路径的点 
int n,m;

void add(int a,int b,int c){
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}

int dijkstra(){
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	
	priority_queue<PII,vector<PII>,greater<PII> > pq;
	pq.push({0,1});                 // 这里必须把路径作为first，堆顶的元素才会是路径最小的点 
	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		
		int var=t.second,dis=t.first;
		if(st[var]) continue;       // 如果该节点的最短路径已经求出，跳过该结点 
		st[var]=1;
		
		for(int i=h[var];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[j]>dis+w[i]){
				dist[j]=dis+w[i];    // 这里要注意w的下标为i 
				pq.push({dist[j],j});
			}
		}
	}
	if(dist[n]==0x3f3f3f3f) return -1;
	else return dist[n];
}

int main(){
	memset(h,-1,sizeof(h));
	int x,y,z;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> x >> y >> z;
		add(x,y,z);
	}
	
	int res = dijkstra();
	
	cout << res << endl;
} 
