#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        if(a[n-1]<n-1){
            cout<<-1<<endl;
            continue;
        }
        int count=0;
        int i=n-2;
        int flag=1;
        while(i>=0){
            if(a[i]<i){
                cout<<-1<<endl;
                flag=0;
                break;
            }
            if(a[i]>=a[i+1]){
                a[i]/=2;
                count++;
            }
            else{
                i--;
            }
        }
        if(flag){
        cout<<count<<endl;
        }
    }
    return 0;
}