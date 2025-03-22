#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int mini=1;
        int maxi=n;
        int i=0;
        int j=n-1;
        int flag=1;
        while(i<j){
            if(a[i]==mini){
                i++;
                mini++;
            }
            else if(a[j]==maxi){
                j--;
                maxi--;
            }
            else if(a[i]==maxi){
                i++;
                maxi--;
            }
            else if(a[j]==mini){
                j--;
                mini++;
            }
            else{
                cout<<i+1<<" "<<j+1<<endl;
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<-1<<endl;
        }
    }
    return 0;
}