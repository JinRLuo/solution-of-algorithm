#include <iostream>
#include <cstring>
#include <queue>
#define PII pair<int,int>
using namespace std;

//Dijkstra���Ż��� ������ϡ��ͼ 

const int maxn = 100010;

int h[maxn],w[maxn],e[maxn],ne[maxn],idx; // �ڽӱ�洢  w����洢��Ȩ 
int dist[maxn],st[maxn];                  // ���·���ͱ������  st��ʾ�Ѿ�������·���ĵ� 
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
	pq.push({0,1});                 // ��������·����Ϊfirst���Ѷ���Ԫ�زŻ���·����С�ĵ� 
	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		
		int var=t.second,dis=t.first;
		if(st[var]) continue;       // ����ýڵ�����·���Ѿ�����������ý�� 
		st[var]=1;
		
		for(int i=h[var];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[j]>dis+w[i]){
				dist[j]=dis+w[i];    // ����Ҫע��w���±�Ϊi 
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
