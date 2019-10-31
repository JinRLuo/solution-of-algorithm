#include <iostream>
#include <cstring>
using namespace std;

// ���·��bellman_ford�㷨 �����ڴ��и�Ȩ��ͼ�Լ��������·����������Ŀ 

const int maxn = 510, maxm = 10010;
int dist[maxn],backup[maxn];
int n,m,k;

struct Edge{    // �ԱߵĴ洢Ҫ�󲻴�ֻҪ�ܱ������б߼��� 
	int a,b,c;  // ���Դ˴��ýṹ��洢�� 
}edges[maxm];

int bellman_ford(){
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0; 
	for(int i=0;i<k;i++){
		memcpy(backup,dist,sizeof(dist));   // ÿ�α������б�֮ǰ��dist���������� 
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
