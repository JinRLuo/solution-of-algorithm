#include <iostream>
#include <string>
#define ULL unsigned long long 
using namespace std;

//字符串哈希
//利用一个P进制数来存取字符串的哈希值P一般取131或13331

const int N = 100010, P = 131;
ULL h[N],p[N];  //h数组为从第1位到第i位的字符串的哈希值 
int n,m;        //p数组存储P的i次方 
char s[N];      //这里有个小技巧，由于用unsignedlonglong存储，所以溢出相当于对2^64取模 

ULL get(int l,int r){
	return h[r]-h[l-1]*p[r-l+1];
}

int main(){
	cin >> n >> m;
	scanf("%s",s+1);
	p[0]=1;
	for(int i=1;i<=n;i++){  //计算第1位到第i位的字符串的哈希值 
		h[i]=h[i-1]*P+s[i];
		p[i]=p[i-1]*P;      // 
	}
	int l1,r1,l2,r2;
	while(m--){
		cin >> l1 >> r1 >> l2 >> r2;
		if(get(l1,r1)==get(l2,r2))  //判断两个字符串的哈希值是否相等 
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
} 
