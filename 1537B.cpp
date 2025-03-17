#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,i,j;
        cin>>n>>m>>i>>j;
        if(i<=n/2){
            if(j<=m/2){
                cout<<1<<" "<<1<<" "<<n<<" "<<m<<endl;
            }
            else{
                cout<<1<<" "<<m<<" "<<n<<" "<<1<<endl;
            }
        }
        else{
            if(j<=m/2){
                cout<<1<<" "<<m<<" "<<n<<" "<<1<<endl;
            }
            else{
                cout<<1<<" "<<1<<" "<<n<<" "<<m<<endl;
            }
        }
    }
    return 0;
}