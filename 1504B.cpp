#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        long long c0=0;
        long long c1=0;
        int flag=1;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(a[i]=='0'){
                    c0++;
                }
                else{
                    c1++;
                }
                if(i==n-1 && c0!=c1){
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
            }
            else{
                if(c0!=c1){
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }

            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}