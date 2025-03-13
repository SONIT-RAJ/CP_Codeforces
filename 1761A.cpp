#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        if(n==1){
            cout<<"YES"<<endl;
        }
        else if(a==n && b==n){
            cout<<"YES"<<endl;
        }
        else if(a+b+1>=n){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}