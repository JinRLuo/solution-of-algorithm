#include <iostream>
#include <cstring>
using namespace std;

int f[20];
int d[20];

int main(){
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=20;i++){
		d[i]=2*d[i-1]+1;
	}
	f[0]=0;
	for(int i=1;i<=12;i++){
		for(int j=0;j<i;j++){
			f[i]=min(f[i],2*f[j]+d[i-j]);
		}
	}
	for(int i=1;i<=12;i++)
		cout << f[i] << endl;
}
