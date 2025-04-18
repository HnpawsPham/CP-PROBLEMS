#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string sol(int n){
    if(n == 1) return "1";
    if(n == 2) return "11";
    
    string s = sol(n - 1);
    int len = s.length(), cnt = 1;

    string res;
    for(int i = 0; i < len; i++){
        if(s[i] == s[i + 1]) cnt++;
        else{
            res += '0' + cnt;
            res += s[i];
            cnt = 1;
        }
    }
    return res;
}

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cout<<sol(n);

    return 0;
}