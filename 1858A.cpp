#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long f,s,t;
        cin>>f>>s>>t;
        if(t%2==0){
            if(f<=s){
                cout<<"Second"<<endl;
            }
            else{
                cout<<"First"<<endl;
            }
        }
        else{
            if(s<=f){
                cout<<"First"<<endl;
            }
            else{
                cout<<"Second"<<endl;
            }
        }

    }
    return 0;
}