//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int N,V;
int f[1005];
int v[1005],w[1005],s[1005];

void ZeroOnePack(int* f,int v1,int w1){
	for(int i=V;i>=0;i--){
		if(i>=v1)
			f[i]=max(f[i],f[i-v1]+w1);
	}
}

void CompletePack(int *f,int v1,int w1){
	for(int i=0;i<=V;i++){
		if(i>=v1)
			f[i]=max(f[i],f[i-v1]+w1);
	}
}

void MultiplePack(int *f,int v1,int w1,int s1){
	int a[1005];
	int b[1005];
	int cnt=1;
	for(int i=1;i<s1;i<<1){
		a[cnt]=i*v1;
		a[cnt++]=i*w1;
		s1-=i;
	}
	if(s1){
		a[cnt]=s1*v1;
		b[cnt++]=s1*w1;
	}
	for(int i=1;i<cnt;i++){
		for(int j=V;j>=0;j--){
			if(j>=a[i])
				f[j]=max(f[j],f[j-a[i]]+b[i]);
		}
	}
}

int main(){
	memset(f,0,sizeof(f));
	cin>>N>>V;
	for(int i=1;i<=N;i++){
		cin>>v[i]>>w[i]>>s[i];
	}
	for(int i=1;i<=N;i++){
		if(s[i]==-1)
			ZeroOnePack(f,v[i],w[i]);
		else if(s[i]==0||s[i]*v[i]>=V) //此处必须加上s[i]>=V 将总体积大于背包容量的物品当作完全背包来处理  
			CompletePack(f,v[i],w[i]); //否则会超时 
		else
			MultiplePack(f,v[i],w[i],s[i]);
	}
	cout << f[V] << endl;
}
