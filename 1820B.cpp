#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int c0=0;
        int c1=0;
        int max1toge=0;
        int max1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')c0++;
            else{
                c1++;
                if(i==0){
                    max1toge++;
                    if(max1<max1toge){
                        max1=max1toge;
                    }
                }
                else if(s[i-1]=='1'){
                    max1toge++;
                    if(max1<max1toge){
                        max1=max1toge;
                    }
                }
                else{
                    max1toge=1;
                    if(max1<max1toge){
                        max1=max1toge;
                    }
                }

            }

        }
        if(c0==0){
            cout<<1LL*c1*c1<<endl;
            continue;
        }
        int i=0;
        int j=s.size()-1;
        while(s[i]=='1' || s[j]=='1'){
            if(s[i]=='1'){
                i++;
            }
            if(s[j]=='1'){
                j--;
            }
        }
        j=s.size()-1-j;
        if(i+j>max1){
            max1=i+j;
        }
        if(c1==0){
            cout<<0<<endl;
            continue;
        }
        else if(max1%2==0){
            cout<<1LL*(max1/2)*(max1/2+1)<<endl;
            continue;
        }
        else{
            cout<<1LL*(max1/2+1)*(max1/2+1)<<endl;
            continue;
        }

    }
    return 0;
}