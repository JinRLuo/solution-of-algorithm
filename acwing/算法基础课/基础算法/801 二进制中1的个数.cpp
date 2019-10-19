#include <iostream>
using namespace std;

int n;

int main(){
	cin>>n;
	int a,res;
	for(int i=0;i<n;i++){
		res=0;
		cin>>a;
		while(a){
			if(a&1){
				res++;
			}
			a>>=1;
		}
		cout << res << " ";
	}
	
} 
