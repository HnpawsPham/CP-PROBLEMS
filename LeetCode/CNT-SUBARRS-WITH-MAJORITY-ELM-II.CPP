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

const int maxn = 2e5 + 5;
int t[maxn];

void update(int i, int val){
    while(i < maxn){
        t[i] += val;
        i += (i & -i);
    }
}

int query(int i){
    int sum = 0;
    while(i > 0){
        sum += t[i];
        i -= (i & -i);
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

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int& x : a){
        if(x == k) x = 1;
        else x = -1;
    }

    vi p(n + 1, 0);
    for(int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];

    ll res = 0;
    int offset = 1e5;

    memset(t, 0, sizeof t);
    update(offset, 1);

    for(int i = 1; i <= n; i++){
        res += query(p[i] + offset - 1);
        update(p[i] + offset, 1);
    }
    cout<<res;
    return 0;
}