// tim so luong mat khau co the sinh co do dai m khi (cac chu cai hoa thuong)
// 1. cac ki tu k duoc trung
// 2. cac ki tu duoc trung
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
string str;
const int maxn = 57;
const ll MOD = (ll)1e9 + 7;

ll ppow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b/=2; 
    }
    return res;
}

void duplicate(){
    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(str[i] == '?') cnt++;
    }
    
    cout<<ppow(maxn, cnt)<<el;
    return;
}

void no_duplicate(){
    ll sum = 1;
    int cnt = 0;

    for(int i = 0; i < n; i++) if(str[i] != '?') cnt++;

    for(int i = 0; i < n; i++){
        if(str[i] == '?') sum =  (sum * (maxn - cnt - i)) % MOD;
    }
    cout<<sum<<el;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>str;

    duplicate();
    no_duplicate();

    return 0;
}