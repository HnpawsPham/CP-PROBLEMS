#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

ll __lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 0;
    for(int i = 0; i < n; i++){ 
        ll mul = 1, lcm = 1, gcd = 0;

        for(int j = i; j < n; j++){
            lcm = __lcm(lcm, 1ULL * a[j]);
            gcd = __gcd(gcd, 1ULL * a[j]);
            mul *= a[j];
            if(mul == gcd * lcm)
                res = max(res, j - i + 1);
        }
    }
    cout<<res;
    return 0;
}