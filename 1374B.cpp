#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<0<<endl;
        }
        else if(n%3!=0){
            cout<<-1<<endl;
        }
        else{
            int c2=0;
            int c3=0;
            while(n%3==0 || n%2==0){
                if(n%3==0){
                    c3++;
                    n/=3;
                }
                if(n%2==0){
                    c2++;
                    n/=2;
                }
            }
            if(n!=1){
                cout<<-1<<endl;
            }
            else if(c2>c3){
                cout<<-1<<endl;
            }
            else{
                cout<<c3+c3-c2<<endl;
            }

        }
    }
    return 0;
}
