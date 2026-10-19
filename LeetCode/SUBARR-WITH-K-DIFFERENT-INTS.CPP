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

int cnt[20005];
int n;

int calc(int k, const vi& a){
    int diff = 0;
    memset(cnt, 0, sizeof cnt);

    int l = 0, res = 0;
    for(int i = 0; i < n; i++){
        if(!cnt[a[i]]) diff++;
        cnt[a[i]]++;

        while(l <= i && diff > k){
            cnt[a[l]]--;
            if(!cnt[a[l]]) diff--;
            l++;
        }
        res += i - l + 1;
    }
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    cout<<calc(k, a) - calc(k - 1, a);
    return 0;
}

// 5 2
// 1 2 1 2 3
