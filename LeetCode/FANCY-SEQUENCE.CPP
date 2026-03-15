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

#define vi vector<int>
using ll = unsigned long long;

class Fancy {
public:
    const int MOD = 1e9 + 7;
    vi a;
    int mul = 1, add = 0; 

    Fancy() {}

    ll ppow(int a, int b){
        if(b == 0) return 1;
        ll half = ppow(a, b / 2);
        if(b & 1) return  half * half % MOD * 1LL * a % MOD;
        return half * half % MOD; 
    }

    ll invmod(int x){
        return ppow(x, MOD - 2);
    }
    
    void append(int val) {
        ll x = ((val - add + MOD) % MOD) * invmod(mul) % MOD;
        a.push_back((int)x);
    }
    
    void addAll(int inc) {
        add = (1LL * add + inc) % MOD;
    }
    
    void multAll(int m) {
        mul = 1LL * mul * m % MOD;
        add = 1LL * add * m % MOD;
    }
    
    int getIndex(int i) {
        if(i >= a.size()) return -1;
        int x = ((1LL * a[i] * 1LL * mul) % MOD + add) % MOD;
        return x;
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}