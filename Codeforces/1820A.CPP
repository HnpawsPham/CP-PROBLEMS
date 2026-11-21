#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int tc = 1;

int sol(){
    string s;
    cin>>s;
    if(s == "^") return 1;

    int cnt = 0, cntm = 0;
    int n = s.length();

    for(int i = 0; i < n ;i++){
        if(s[i] == '^'){
            cnt += max(0, cntm - 1);
            cntm = 0;
        }
        else{
            if(i == 0) cnt++;
            cntm++;
        }
    }
    return cnt + cntm;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}