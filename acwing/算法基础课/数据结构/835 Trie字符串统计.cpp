#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e5+10;
int son[maxn][30];//一维下标表示父节点的idx值，二维下标为该字母对应的数字 
int cnt[maxn];    //cnt表示已该字符结尾的字符串数量，cnt下标为该字符串的idx值 
int idx=0;        //从1开始为每个新结点分配idx，每个结点都有一个唯一的idx值，存在son数组中 
void insert(string s){
	int p=0;      //0代表根节点 
	for(int i=0;s[i];i++){
		int u=s[i]-'a';
		if(!son[p][u]) son[p][u]=++idx;
		p = son[p][u];
	}
	cnt[p]++;    //字符串树加一 
}

int query(string s){
	int p=0;
	for(int i=0;s[i];i++){
		int u=s[i]-'a';
		if(!son[p][u]) return 0;
		p = son[p][u];
	}
	return cnt[p];
}

int main(){
	string s;
	char c;
	int n;
	cin>>n;
	while(n--){
		cin>>c>>s;
		if(c=='I'){
			insert(s);
		}else{
			cout << query(s) << endl;
		}
	}
} 
