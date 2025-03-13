#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b>d || d-b+a<c){
            cout<<-1<<endl;
        }
        else{
            if(d==b){
                cout<<a-c<<endl;
            }
            else{
                int p=d-b;
                cout<<p+(a-(c-p))<<endl;
            }
        }
    }
    return 0;
}