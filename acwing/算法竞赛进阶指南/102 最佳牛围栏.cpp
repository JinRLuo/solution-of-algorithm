#include <bits/stdc++.h>
using namespace std;

double d[100050];
double sum[100050];
int n,f;

//利用前缀+二分法 
int check(double m){
	double mind=0,avgs=0;
	for(int i=0;i<n;i++){
		sum[i]=sum[i-1]+d[i]-m; 
	}
	for(int i=f-1;i<n;i++){
		mind = min(mind,sum[i-f]);
		avgs = max(sum[i]-mind,avgs);
	}
	return avgs>0?1:0;
}

int main(){
	int res;
	double l=0,r=0,mid;
	double avg,mavg=0;
	cin >> n >> f;
	for(int i=0;i<n;i++){
		cin >> d[i];
		r=max(r,d[i]);
	}
	while(r-l>1e-5){  //对l到r进行二分 直到l和r之间的差距小于1e-5 
		mid=(l+r)/2;
		if(check(mid))//判断此平均数是否有可能 
			l=mid;
		else
			r=mid;
	}
	res=r*1000;
	cout << res << endl;
} 

/*
利用前缀和计算平均数 
int main(){
	int n,f,res;
	double avg,mavg=0;
	cin >> n >> f;
	for(int i=0;i<n;i++){
		cin >> d[i];
		sum[i]=sum[i-1]+d[i];
	}
	for(int i=0;i<=n-f;i++){
		for(int j=i+f-1;j<n;j++){
			avg=(double)(sum[j]-sum[i-1])/(j+1-i);
			mavg=max(mavg,avg);
		}
	}
	res=mavg*1000;
	cout << res << endl;
}
*/
