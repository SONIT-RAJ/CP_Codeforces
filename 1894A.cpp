#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int flag=0;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            if(i==0 && x==1){
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