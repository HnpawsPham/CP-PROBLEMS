#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    pii a[n];
    int cnt[k + 1] = {0};
    for(int i = 0; i < n; i++) {
        cin>>a[i].se;
        cnt[a[i].se]++;
    }
    for(int i = 0; i < n; i++) cin>>a[i].fi;

    sort(a, a + n);
    int need = 0;
    for(int i = 1; i <= k; i++) need += (cnt[i] == 0);

    ll res = 0;
    for(int i = 0; i < n && need > 0; i++){
        if(cnt[a[i].se] > 1){
            res += a[i].fi;
            cnt[a[i].se]--;
            need--;
        }
    }
    cout<<res;
    return 0;
}