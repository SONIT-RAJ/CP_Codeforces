#include<iostream>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        int flag=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(k==x){
                flag=1;
            }
        }
        if(flag==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}