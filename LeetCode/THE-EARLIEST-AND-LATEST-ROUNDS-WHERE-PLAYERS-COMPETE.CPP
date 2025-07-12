#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define checkbit(mask, i) (mask & (1 << i))
#define onbit(mask, i) (mask | (1 << i)) 
#define offbit(mask, i) (mask & ~(1 << i))
#define vi vector<int>
#define pii pair<int, int>

int n, fi, se;
const int maxn = 30;
int idx[maxn];
bool lose[maxn];
int minn = maxn, maxx = 0;
unordered_map<int, pii> memo;

void gen(int i, int len, int mask, vi& v, vi& a){
    if(i == len / 2){
        if(len % 2) mask = onbit(mask, a[len / 2] - 1);
        v.push_back(mask);
        return;
    }

    int x = a[i], y = a[len - i - 1];
    if(x == fi || x == se) 
        gen(i + 1, len, onbit(mask, x - 1), v, a);

    else if(y == fi || y == se) 
        gen(i + 1, len, onbit(mask, y - 1), v, a);

    else{
        gen(i + 1, len, onbit(mask, x - 1), v, a);
        gen(i + 1, len, onbit(mask, y - 1), v, a);
    }
    return;
}

pii sol(int mask, int round){
    if(memo.count(mask)) return memo[mask];

    vi a;
    for(int i = 0; i < n; i++)
        if(checkbit(mask, i)) a.push_back(i + 1);

    int m = a.size();
    for(int i = 0; i < m / 2; i++){
        int x = a[i], y = a[m - i - 1];
        if((x == fi && y == se) || (x == se && y == fi))
            return memo[mask] = {round, round};
    }

    vi v;
    gen(0, m, 0, v, a);

    int maxx = 0, minn = 30;
    for(int mask : v){
        auto [mn, mx] = sol(mask, round + 1);
        minn = min(minn, mn);
        maxx = max(maxx, mx);
    }
    return {minn, maxx};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>fi>>se;
    int st = (1 << n) - 1;
    auto [minn, maxx] = sol(st, 1);
    cout<<minn<<" "<<maxx;
    return 0;
}