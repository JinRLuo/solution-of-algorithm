#include <iostream>
#include <cstring>
using namespace std;

//��С������ prim�㷨
//����stΪ�������ļ���
//ÿ����ͼ���ҵ��뼯�Ͼ�����̵ĵ�(�˱߾�����С�������ı�)��������뼯�ϲ������������뼯�ϵľ��� 
//�����������ظ�n�� 

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
		if(i&&dist[t]==INF) return INF;  //�����������뼯�ϵ���̾���ΪINF,˵���õ���������֮��û�б�,��û����С������ 
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
