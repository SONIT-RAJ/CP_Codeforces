#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<" "<<0<<endl;
            continue;
        }
        if(a>b){
            long long temp=b;
            b=a;
            a=temp;
        }
        long long g=b-a;
        if(b%g==a%g){
            long long d=b%g;
            cout<<g<<" "<<min(d,g-d)<<endl;
        }
        else{
            cout<<g<<" "<<a<<endl;
        }
    }
    return 0;
}