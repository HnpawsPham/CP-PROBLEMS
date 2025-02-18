#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 998244353
#define bit(mask, i) ((mask >> i)&1)

int n;
const int maxn = (int)1e6 + 5;
ll s, cnt = 0;
ll a[maxn];

void bitmask(){
    for(int i = 0; i < (1 << n); i++){
        ll sum = 0;
        for(int j = 0; j <n;j++){
            if(bit(i, j)) sum += a[j];
        }
        cnt += (sum == s);
    }
    return;
}

int main(){
    freopen(".\\txt\\DOOR.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    for(int i =0;i<n;i++) cin>>a[i];
    bitmask();

    cout<<cnt % MOD<<el;
    
    return 0;
}