#include <iostream>
#include <string>
#define ULL unsigned long long 
using namespace std;

//�ַ�����ϣ
//����һ��P����������ȡ�ַ����Ĺ�ϣֵPһ��ȡ131��13331

const int N = 100010, P = 131;
ULL h[N],p[N];  //h����Ϊ�ӵ�1λ����iλ���ַ����Ĺ�ϣֵ 
int n,m;        //p����洢P��i�η� 
char s[N];      //�����и�С���ɣ�������unsignedlonglong�洢����������൱�ڶ�2^64ȡģ 

ULL get(int l,int r){
	return h[r]-h[l-1]*p[r-l+1];
}

int main(){
	cin >> n >> m;
	scanf("%s",s+1);
	p[0]=1;
	for(int i=1;i<=n;i++){  //�����1λ����iλ���ַ����Ĺ�ϣֵ 
		h[i]=h[i-1]*P+s[i];
		p[i]=p[i-1]*P;      // 
	}
	int l1,r1,l2,r2;
	while(m--){
		cin >> l1 >> r1 >> l2 >> r2;
		if(get(l1,r1)==get(l2,r2))  //�ж������ַ����Ĺ�ϣֵ�Ƿ���� 
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
} 
