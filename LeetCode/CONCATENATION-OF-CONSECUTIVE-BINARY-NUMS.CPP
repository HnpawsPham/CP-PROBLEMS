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

const int MOD = 1e9 + 7;

string tobin(int x){
    string s;
    while(x > 0){
        s.push_back(x % 2 + '0');
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

ll ppow(int b){
    if(b == 0) return 1;
    ll half = ppow(b / 2);
    if(b & 1) return half * half % MOD * 2 % MOD;
    return half * half % MOD;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int binlen[100001] = {0};
    for(int i = 1; i <= n; i++)
        binlen[i] = tobin(i).length();
    
    // int res = 0, sz = s.size();
    // for(int i = 0; i < sz; i++)
    //     res += ppow(i) * (s[sz - i - 1] - '0') % MOD;
    // cout<<res;
    ll res = 0;
    for(int i = 1; i <= n; i++){
        res = ((res << binlen[i]) % MOD + i) % MOD;
    }
    cout<<res;
    return 0;
}