#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> > vt;
int n;

int cmp(pair<int,int> v1,pair<int,int> v2){
	if(v1.first<v2.first)
		return 1;
	return 0;
}

int main(){
	int l,r;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		vt.push_back({l,r});
	}
	
	sort(vt.begin(),vt.end());
	
	int count=1;
	pair<int,int> p=vt[0];
	for(int i=1;i<n;i++){
		if(p.second<vt[i].first){
			count++;
			p.first=vt[i].first;
			p.second=vt[i].second;
		}else if(p.second>=vt[i].first&&p.second<=vt[i].second){
			p.second=vt[i].second;
		}
	}
	cout << count << endl;
} 
