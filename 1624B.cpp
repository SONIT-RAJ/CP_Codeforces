#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;
        if(b-a==c-b){
            cout<<"YES"<<endl;
        }
        else if((c+a)%2==0 && ((c+a)/2)%b==0){
            cout<<"YES"<<endl;
        }
        else if((b-(c-b))>0 && (b-(c-b))%a==0){
            cout<<"YES"<<endl;
        }
        else if((b+(b-a))>0 && (b+(b-a))%c==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}