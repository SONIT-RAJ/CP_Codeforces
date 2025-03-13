#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x;
        int y;
        cin>>x>>y;
        int min=y-x;
        x=y;
        for(int i=2;i<n;i++){
            cin>>y;
            if(min>y-x){
                min=y-x;
            }
            x=y;

        }
        if(min<0){
            cout<<0<<endl;
        }
        else{
            cout<<min/2+1<<endl;
        }
    }
    return 0;
}