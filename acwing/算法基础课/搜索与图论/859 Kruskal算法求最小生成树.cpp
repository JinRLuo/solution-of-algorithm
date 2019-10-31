#include <iostream>
#include <algorithm> 
using namespace std;

//Kruskal求最小生成树
//起始时每个点看作一个集合，从小到大遍历所有边
//如果该边所连的两点不属于同一个集合，将两个集合合并，计数值cnt++ 
//直到遍历完所有边，如果cnt值也就是生成树的边数小于n-1,则不存在最小生成树 

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
