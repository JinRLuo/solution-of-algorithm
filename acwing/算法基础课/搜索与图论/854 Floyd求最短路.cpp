#include <iostream>
#include <cstring>
using namespace std;

// floyd���·�㷨�����ڶ�̬�滮�� ���������Դ�����· ʱ�临�Ӷ�O(n^3) 

const int N = 205;
int d[N][N];
int n,m,k;

void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main(){
	int x,y,z;
	memset(d,0x3f,sizeof(d)); 
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		cin >> x >> y >> z;
		d[x][y]=min(d[x][y],z);  //�ӵ� ������ܴ����رߣ���������Ҫȡ��С��
	}
	for(int i=1;i<=n;i++)
		d[i][i]=0; 
	
	floyd();
	
	for(int i=0;i<k;i++){
		cin >> x >> y;
		if(d[x][y]>0x3f3f3f3f/2) cout << "impossible" << endl;
		else cout << d[x][y] << endl;
	}
} 
