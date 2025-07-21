#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    char prev = '-';
    int cnt = 1;
    string res = "";

    for(const char& x : s){
        if(x == prev) cnt++;
        else cnt = 1;
        prev = x;

        if(cnt < 3) res += x;
    }
    cout<<res;
    return 0;
}