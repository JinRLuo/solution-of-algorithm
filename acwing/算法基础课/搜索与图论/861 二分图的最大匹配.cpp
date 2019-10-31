#include <iostream>
#include <cstring> 
using namespace std;

//�������㷨�����ͼ�����ƥ��
 
const int N = 510, M = 100010;
int h[N],e[M],ne[M],idx;
int n1,n2,m;
int match[N],st[N];

int find(int k){
	for(int i=h[k];i!=-1;i=ne[i]){
		int j=e[i];
		if(!st[j]){
			st[j]=1;
			if(!match[j]||find(match[j])){
				match[j]=k;
				return 1;
			}
		}
	}
	return 0;
}

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
int main(){
	int a,b;
	memset(h,-1,sizeof(h));
	cin >> n1 >> n2 >> m;
	while(m--){
		cin >> a >> b; 
		add(a,b);
	}
	int cnt=0;
	for(int i=1;i<=n1;i++){
		memset(st,0,sizeof(st));  //st����Ϊ��ǰ�ѿ��ǹ��ĵ� 
		if(find(i))
			cnt++;
	}
	
	cout << cnt << endl;
} 
