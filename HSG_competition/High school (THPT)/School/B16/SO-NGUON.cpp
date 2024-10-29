#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str;
int n;

string minus_str(){
    string res = "";
    int len = str.length();
    int t = 1;
    bool ok = 0;

    for(int i = len - 1; i >= 0; i--){
        int c = int(str[i] - '0');
        if(c < t){
            c += 10;
            t++;
        }    
        else ok = 1;

        res = to_string(c - t) + res;
        if(ok) t = 0;
    }
    return res;
}

int main(){
    freopen(".\\txt\\SO-NGUON.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    n = str.length();

    if(n < 2){
        cout<<-1<<el;
        return 0;
    }
    
    cout<<minus_str()<<el;

    return 0;
}