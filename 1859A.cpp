#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count=0;
        int max=INT_MIN;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>max){
                max=a[i];
                count=1;
            }
            else if(a[i]==max){
                count++;
            }
        }
        if(count==n){
            cout<<-1<<endl;
        }
        else{
            cout<<n-count<<" "<<count<<endl;
            for(int i=0;i<n;i++){
                if(a[i]!=max){
                    cout<<a[i]<<" ";
                }
            }
            cout<<endl;
            for(int i=0;i<count;i++){
                cout<<max<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}