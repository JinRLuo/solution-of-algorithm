#include <iostream>
#include <cstring>
using namespace std;

//染色法判定二分图 

const int N = 100010;
int h[N],e[2*N],ne[2*N],idx;  //由于是无向图,边数须取2N 
int cl[N];
int n,m;

void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

int dfs(int x,int c){
	cl[x]=c;
	for(int i=h[x];i!=-1;i=ne[i]){
		int j=e[i];
		if(!cl[j]){
			if(!dfs(j,3-c))
				return 0;
		}	else if(cl[j]==c)
			return 0;
	}
	return 1;
}

int main(){
	memset(h,-1,sizeof(h)); 
	int a,b; 
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		add(a,b);
		add(b,a);
	}
	int flag=0;
	for(int i=1;i<=n;i++){  //不一定是连通图，所以每个点都要深搜一次 
		if(!cl[i]){
			if(!dfs(i,1)){
				flag=1;
				break;
			}
		}
	}
	if(flag) cout << "No" << endl;
	else cout << "Yes" << endl;
} 
