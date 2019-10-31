#include <iostream>
using namespace std;

int n;
int r[10];
int f[10];

void dfs(int x){
    if(x==n+1){
        for(int i=1;i<=n;i++)
            cout << r[i] << " ";
        cout << endl;
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(!f[i]){
            r[x]=i;
            f[i]=1;
            dfs(x+1);
            f[i]=0;
        }
    }
}

int main(){
    cin>>n;
    
    dfs(1);
    
    return 0;
}
