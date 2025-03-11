#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<2*n-1<<endl;
        int x;
        cin>>x;
        cout<<x<<" ";
        int y;
        for(int i=1;i<n;i++){
            cin>>y;
            cout<<min(x,y)-1<<" "<<y<<" ";
            x=y;
        }
        cout<<endl;
    }
    return 0;
}