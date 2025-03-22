#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s;
        cin>>t;
        unordered_map<char,int>mpp;
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }
        int flag=1;
        int j=t.size()-1;
        for(int i=s.size()-1;i>=0 && j>=0;i--){
            if(s[i]==t[j]){
                    mpp[s[i]]--;
                    j--;
                    if(j==-1){
                        cout<<"YES"<<endl;
                        flag=0;
                        break;
                    }

            }
            else if (mpp.find(s[i]) != mpp.end() && mpp[s[i]]>0) {
                cout<<"NO"<<endl;
                    flag=0;
                    break;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }

    }
    return 0;
}