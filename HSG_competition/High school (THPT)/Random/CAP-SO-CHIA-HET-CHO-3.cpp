#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    int cnt[3];
    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < n; ++i) {
        ll x; cin>>x;
        cnt[x % 3]++;
    }
   
    ll res = 1LL * cnt[0] * (cnt[0] - 1) / 2 + 1LL * cnt[1] * cnt[2];
    cout<<res;
    return 0;
}