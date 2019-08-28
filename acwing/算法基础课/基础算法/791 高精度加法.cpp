#include <iostream>
#include <string> 
#include <vector>
using namespace std;

string a,b;
vector<int> A,B;

vector<int> add(vector<int> c,vector<int> d){
	int t=0;
	vector<int> e;
	for(int i=0,j=0;i<c.size()||j<d.size();i++,j++){
		if(i<c.size()) t+=c[i];
		if(j<d.size()) t+=d[i];
		e.push_back(t%10);
		t/=10;
	}
	if(t!=0)
		e.push_back(1);
	return e;
	
} 

int main(){
	cin>>a>>b;
	for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
	for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
	auto C=add(A,B);
	for(int i=C.size()-1;i>=0;i--) cout << C[i];
	cout << endl;
	return 0;
} 
