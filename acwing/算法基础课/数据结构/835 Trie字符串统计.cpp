#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e5+10;
int son[maxn][30];//һά�±��ʾ���ڵ��idxֵ����ά�±�Ϊ����ĸ��Ӧ������ 
int cnt[maxn];    //cnt��ʾ�Ѹ��ַ���β���ַ���������cnt�±�Ϊ���ַ�����idxֵ 
int idx=0;        //��1��ʼΪÿ���½�����idx��ÿ����㶼��һ��Ψһ��idxֵ������son������ 
void insert(string s){
	int p=0;      //0������ڵ� 
	for(int i=0;s[i];i++){
		int u=s[i]-'a';
		if(!son[p][u]) son[p][u]=++idx;
		p = son[p][u];
	}
	cnt[p]++;    //�ַ�������һ 
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
