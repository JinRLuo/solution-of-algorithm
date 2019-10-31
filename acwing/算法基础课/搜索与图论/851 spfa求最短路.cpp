#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// spfa���·�㷨  �����ڴ��и�Ȩ�ߵ���Ŀ
// �������ж����޸�Ȩ��  

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
	queue<int> q;           //�ö������洢���¹��ĵ� 
	q.push(1);
	st[1]=1;                //��dijkstra��ͬ���ǣ������st����������ǵ�ǰ�ڶ����еĽ�� 
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		st[t]=0;
		for(int i=h[t];i!=-1;i=ne[i]){  //�Խ��ɵ���ĵ���¾��� 
			int j = e[i];
			if(dist[j]>dist[t]+w[i]){
				dist[j]=dist[t]+w[i];
				if(!st[j]){             //���Ѹ�����δ�ڶ����еĵ������� 
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
