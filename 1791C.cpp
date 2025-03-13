#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int i,j;
        for(i=0,j=n-1;i<j;i++,j--){
            if(s[i]=='0' && s[j]=='1'){
                continue;
            }
            else if(s[i]=='1' && s[j]=='0'){
                continue;
            }
            else{
                break;
            }
        }
        if(i==j){
            cout<<1<<endl;
        }
        else if(i>j){
            cout<<0<<endl;
        }
        else{
            cout<<j-i+1<<endl;
        }

    }
    return 0;
}