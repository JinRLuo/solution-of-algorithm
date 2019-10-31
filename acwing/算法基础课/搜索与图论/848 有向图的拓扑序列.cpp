#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 100010;
int h[maxn],e[maxn],ne[maxn],idx; //�ڽӱ� 
int top[maxn];//�洢�����Ľ�� 
int d[maxn];  //�洢��� 
int n,m;
queue<int> q;

void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

int topsort(){
	int cnt=0;//�Ѿ�����Ľ���� 
	for(int i=1;i<=n;i++){
		if(!d[i]){
			q.push(i);
			top[cnt++]=i;
		}
	}
	while(!q.empty()){
		int k = q.front();
		q.pop();
		for(int i=h[k];i!=-1;i=ne[i]){
			d[e[i]]--;
			if(!d[e[i]]){
				q.push(e[i]);
				top[cnt++]=e[i];
			}
		}
	}
	if(cnt<n)
		return 0;
	else
		return cnt;
} 

int main(){
	memset(h,-1,sizeof(h));
	int a,b;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		add(a,b); 
		d[b]++;
	}
	int res = topsort();
	if(!res){
		cout << -1 << endl;
	}else{
		for(int i=0;i<res;i++){
			cout << top[i] << " ";
		}
		cout << endl; 
	}
	
	return 0;
} 
