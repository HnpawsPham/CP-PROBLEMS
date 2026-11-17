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

const int maxn = 4e4 + 5;
bool dp[maxn];

struct block{
    int h, lim, cnt;
    block(){};
    block(int h1, int lim1, int cnt1) : h(h1), lim(lim1), cnt(cnt1){};

    bool operator<(const block& other){
        return lim < other.lim;
    }
};

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
    block a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i].h>>a[i].lim>>a[i].cnt;

    sort(a, a + n);
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < a[i].cnt; j++){
            for(int h = a[i].lim; h >= a[i].h; h--)
                dp[h] |= dp[h - a[i].h];
        }
    
    for(int i = maxn - 1; i >= 0; i--)
        if(dp[i]) 
            return cout<<i, 0;
    return 0;
}