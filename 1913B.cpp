#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string n;
        cin>>n;
        int c0=0;
        int c1=0;
        for(int i=0;i<n.size();i++){
            if(n[i]=='0')c0++;
            else{
                c1++;
            }
        }
        for(int i=0;i<n.size();i++){
            if(n[i]=='0')c1--;
            else{
                c0--;
            }
            if(c0<0 || c1<0){
                cout<<n.size()-i<<endl;
                break;
            }
            if(i==n.size()-1){
                cout<<0<<endl;
            }
        }

    }
    return 0;
}