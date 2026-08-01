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
const int maxn = 2e5 + 5;
int t[maxn];

void update(int i, int val){
    while(i <= n){
        t[i] += val;
        i += (i & -i);
    }
}

int query(int i){
    int sum = 0;
    while(i > 0){
        sum += t[i];
        i -= i & (-i);
    }
    return sum;
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
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    int x = 1;
    ll maxx = -1;
    ll cnt[n + 2] = {0};
    for(int i = 1; i <= n; i++){
        cnt[a[i]] = i - 1 - query(a[i]);
        update(a[i], 1);
    }   

    memset(t, 0, sizeof t);
    for(int i = n; i > 0; i--){
        cnt[a[i] + 1] -= query(a[i] - 1);
        update(a[i], 1);
    }

    for(int i = 1; i <= n; i++){
        cnt[i] += cnt[i - 1];
        if(cnt[i] > maxx){
            maxx = cnt[i];
            x = i;
        }
    }
    cout<<x<<" "<<maxx;
    return 0;
}