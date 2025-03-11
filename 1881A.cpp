#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string x,s;
        cin>>x>>s;
        if (x.find(s) != string::npos) {
            cout <<0<< endl;
            continue;
        }
        for(int i=1;i<=5;i++){
            x+=x;
            if (x.find(s) != string::npos) {
                cout <<i<< endl;
                break;
            }
            else if(i==5){
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}