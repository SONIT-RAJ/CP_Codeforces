#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        if(n%2==0){
            if(k%n==0){
                cout<<n<<endl;
            }
            else{
                cout<<k%n<<endl;
            }
        }
        else{
            long long d=n/2;
            long long t=(k-1)/d;
            t+=k;
            if(t%n==0){
                cout<<n<<endl;
            }
            else{
                cout<<t%n<<endl;
            }
        }

    }
    return 0;
}