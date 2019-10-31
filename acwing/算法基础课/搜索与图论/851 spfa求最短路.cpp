#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// spfa最短路算法  适用于带有负权边的题目
// 可用来判断有无负权边  

const int maxn = 100010;
int h[maxn],e[maxn],w[maxn],ne[maxn],idx;
int dist[maxn],st[maxn];
int n,m;

void add(int x,int y,int z){
	e[idx]=y;
	w[idx]=z;
	ne[idx]=h[x];
	h[x]=idx++;
}

int spfa(){
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	queue<int> q;           //用队列来存储更新过的点 
	q.push(1);
	st[1]=1;                //与dijkstra不同的是，这里的st数组用来标记当前在队列中的结点 
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		st[t]=0;
		for(int i=h[t];i!=-1;i=ne[i]){  //对结点可到达的点更新距离 
			int j = e[i];
			if(dist[j]>dist[t]+w[i]){
				dist[j]=dist[t]+w[i];
				if(!st[j]){             //将已更新且未在队列中的点加入队列 
					q.push(j);
					st[j]=1;
				}
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
	
	int res = spfa();
	
	if(res==-1) cout << "impossible" << endl;
	else cout << res << endl;
	return 0; 
} 
