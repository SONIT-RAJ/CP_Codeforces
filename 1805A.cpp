#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x=0;
        int y;
        for(int i=0;i<n;i++){
            cin>>y;
            x^=y;
        }
        if(n%2==1 || x==0){
            cout<<x<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}