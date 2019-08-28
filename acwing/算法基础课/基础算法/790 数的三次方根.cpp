#include <iostream>
using namespace std;

double n;

int main(){
    int flag=0;
    cin>>n;
    if(n<0){
        n=-n;
        flag=1;
    }
    double l=0,r=n;
    while(r-l>1e-8){
        double mid=(l+r)/2;
        if(mid*mid*mid>n)
            r=mid;
        else
            l=mid;
    }
    if(flag)
        printf("-%.6lf",l);
    else
        printf("%.6lf",l);
}
