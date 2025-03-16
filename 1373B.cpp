#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int size=s.size();
        int c=0;
        for(int i=0;i<size;i++){
            if(s[i]=='0')c++;
        }
        int ans=min(c,size-c);
        if(ans%2==0){
            cout<<"NET"<<endl;
        }
        else{
            cout<<"DA"<<endl;
        }
    }
    return 0;
}