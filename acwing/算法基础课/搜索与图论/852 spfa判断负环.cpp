#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// spfa最短路算法判断负环 

const int N = 10010;
int h[N],e[N],ne[N],w[N],idx;//虽然此题最多只有2000个结点，但最多有10000条边，所以链表的长度应该定义长一点 
int cnt[N];                  //增加cnt数组表示到达该节点的边数 
int dist[N],st[N];    
int n,m;

int spfa(){
	//此题无需求最短路，所以不用初始化dist数组 
	queue<int> q;
	for(int i=1;i<=n;i++){  //由于可能存在从结点1无法到达的负环，所以刚开始必须将所有结点加入队列 
	    q.push(i);
	    st[i]=1;
	}
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		st[t]=0;
		for(int i=h[t];i!=-1;i=ne[i]){
			int j = e[i];
			if(dist[j]>dist[t]+w[i]){
				dist[j]=dist[t]+w[i];
				cnt[j]=cnt[t]+1;
				if(cnt[j]>=n) return 1;   //如果存在到达该节点的边数大于等于n的 
				if(!st[j]){               //说明到达该节点需要经过至少n+1个点 
					q.push(j);			  //所以图中必定存在负环 
					st[j]=1;
				}
			}
		}
	}
	return 0;
}

void add(int x,int y,int z){
	e[idx]=y;
	w[idx]=z;
	ne[idx]=h[x];
	h[x]=idx++;
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
	
	if(res) cout << "Yes" << endl;
	else cout << "No" << endl; 
} 
