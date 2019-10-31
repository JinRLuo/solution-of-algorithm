#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// spfa���·�㷨�жϸ��� 

const int N = 10010;
int h[N],e[N],ne[N],w[N],idx;//��Ȼ�������ֻ��2000����㣬�������10000���ߣ���������ĳ���Ӧ�ö��峤һ�� 
int cnt[N];                  //����cnt�����ʾ����ýڵ�ı��� 
int dist[N],st[N];    
int n,m;

int spfa(){
	//�������������·�����Բ��ó�ʼ��dist���� 
	queue<int> q;
	for(int i=1;i<=n;i++){  //���ڿ��ܴ��ڴӽ��1�޷�����ĸ��������Ըտ�ʼ���뽫���н�������� 
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
				if(cnt[j]>=n) return 1;   //������ڵ���ýڵ�ı������ڵ���n�� 
				if(!st[j]){               //˵������ýڵ���Ҫ��������n+1���� 
					q.push(j);			  //����ͼ�бض����ڸ��� 
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
