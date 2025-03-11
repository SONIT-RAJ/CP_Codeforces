#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x1;
        cin>>n>>x1;
        int max=0;
        int x,y;
        y=0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(max<x-y){
                max=x-y;
            }
            y=x;
        }
        if(max<2*(x1-y)){
            max=2*(x1-y);
        }
        cout<<max<<endl;
    }
    return 0;
}