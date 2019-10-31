#include <iostream>
#include <algorithm> 
using namespace std;

//Kruskal����С������
//��ʼʱÿ���㿴��һ�����ϣ���С����������б�
//����ñ����������㲻����ͬһ�����ϣ����������Ϻϲ�������ֵcnt++ 
//ֱ�����������бߣ����cntֵҲ�����������ı���С��n-1,�򲻴�����С������ 

const int N = 100010;
int d[N];
int n,m;

struct edgs{
	int u,v,w;
}e[2*N]; 

int cmp(edgs e1,edgs e2){
	return e1.w<e2.w;
}

int find(int x){
	if(d[x]==x) return x;
	return d[x]=find(d[x]);
}

int kruskal(){
	int res=0,cnt=0;
	for(int i=0;i<m;i++){
		int a=find(e[i].u),b=find(e[i].v);
		if(a!=b){
			d[a]=b;
			res+=e[i].w;
			cnt++;
		}
	}
	
	if(cnt<n-1) return -1;
	else return res;
	
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<=n;i++) d[i]=i;
	
	for(int i=0;i<m;i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	
	sort(e,e+m,cmp);
	
	int res = kruskal();
	
	if(res==-1){
		cout << "impossible" << endl;
	}else
		cout << res << endl;
	
}
