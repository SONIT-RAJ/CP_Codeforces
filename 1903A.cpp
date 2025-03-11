#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int k;
        cin>>n>>k;
        int flag=0;
        int x;
        cin>>x;
        int y;
        for(int i=1;i<n;i++){
            cin>>y;
            if(y<x && flag==0){
                flag=1;
            }
            x=y;

        }
        if(k!=1){
            cout <<"YES"<<endl;
        }
        else{
            if(flag==0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}