#include <iostream>
#include <cstring>
using namespace std;

// dijkstra��������  �����ڳ���ͼ
// ʱ�临�Ӷ�O(n^2) 

const int maxn = 510;
int g[maxn][maxn];//�ڽӾ��� 
int dist[maxn];   //Դ�㵽��������·�� 
int st[maxn];     //��㼯 
int n,m; 

int dijkstra(){
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	                                 //���·��ʵ�������ظ�����������̣�ֱ�����еĵ㶼���뼯�� 
	for(int i=0;i<n;i++){            //�Ӳ���st���ϵĵ���ѡһ��·����̵ĵ� 
		int t=-1;
		for(int j=1;j<=n;j++){
			if(!st[j]&&(t==-1||dist[j]<dist[t]))
				t=j;
		}
		
		st[t]=1;                     //���������뼯�� 
		
		for(int j=1;j<=n;j++){       //�������е�����·�� 
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
