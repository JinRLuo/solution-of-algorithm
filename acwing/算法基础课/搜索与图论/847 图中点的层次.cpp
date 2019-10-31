#include <iostream>
#include <cstring>
#include <queue> 
using namespace std;

const int maxn = 100010;
int h[maxn],f[maxn];
int e[maxn],ne[maxn],idx;
int n,m;
queue<int> q;

void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
} 

void bfs(){
	while(!q.empty()){
		int k = q.front();
		q.pop();
		for(int i=h[k];i!=-1;i=ne[i]){
			if(!f[e[i]]){
				f[e[i]]=f[k]+1;
				q.push(e[i]);
			}
		}
	}
	
}

int main(){
	int a,b; 
	memset(h,-1,sizeof(h));
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		add(a,b);
	}
	
	q.push(1);
	bfs();
	
	if(f[n])
		cout << f[n] << endl;
	else
		cout << "-1" << endl;
}
