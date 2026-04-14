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

int n;
const int MOD = 1e6 + 3;

int ppow(int a, int b){
    if(b <= 0) return 1;
    int half = ppow(a, b / 2);
    if(b & 1) return 1LL * half * 1LL * half % MOD * 1LL * a % MOD;
    return 1LL * half * half % MOD;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cout<<ppow(3, n - 1);
    return 0;
}