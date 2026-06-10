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

const int maxn = 1e4 + 5;

ll C4(ll x){
    return x * (x - 1) * (x - 2) * (x - 3) / 24;
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
    while(cin>>n){
        int a[n];
        int maxa = 1;
        int cnt[maxn] = {0};
        for(int i = 0; i < n; i++){
            cin>>a[i];
            maxa = max(maxa, a[i]);
            cnt[a[i]]++;
        }

        for(int i = 1; i <= maxa; i++)
            for(int j = i + i; j <= maxa; j+=i)
                cnt[i] += cnt[j];

        ll sum[maxa + 1] = {0};
        for(int i = maxa; i > 0; i--){
            sum[i] = C4(cnt[i]);
            for(int j = i + i; j <= maxa; j+=i)
                sum[i] -= sum[j];
        }
        cout<<sum[1]<<el;
    }
    return 0;
}