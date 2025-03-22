#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,k,x;
        cin>>n>>k>>x;
        long long front=(1LL*k*(k+1))/2;
        long long back=(1LL*k*(n+n+1-k))/2;
        if(x<front){
            cout<<"NO"<<endl;
        }
        else if(x>back){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}