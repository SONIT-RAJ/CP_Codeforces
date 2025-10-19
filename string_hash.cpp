#include<bits/stdc++.h>
using namespace std;

long long g_hash(string s){
    long long h=0;
    for(char c: s)h=(h*31+(c-'a'+1))%100000007;
    return h;
}

int main(){
    cout<<g_hash("abc");
    return 0;
}