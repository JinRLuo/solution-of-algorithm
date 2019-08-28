#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> mul(vector<int> a,int b){
	vector<int> c;
	int t=0;
	for(int i=0;i<a.size();i++){
		t+=a[i]*b;
		c.push_back(t%10);
		t/=10;
	}
	while(t){
		c.push_back(t%10);
		t/=10;
	}
	return c;
}

int main(){
	string A;
	vector<int>a;
	int b;
	cin>>A>>b;
	for(int i=A.size()-1;i>=0;i--) a.push_back(A[i]-'0');
	
	auto c = mul(a,b);
	
	for(int i=c.size()-1;i>=0;i--) cout << c[i];
	cout << endl;
	
}
