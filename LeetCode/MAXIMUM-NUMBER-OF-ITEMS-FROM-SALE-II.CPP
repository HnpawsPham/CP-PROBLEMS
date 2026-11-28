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

const int maxn = 1e5 + 5;
static int f[maxn];
static int cnt[maxn];

bool comp(const vi& a, const vi& b){
    return a[1] < b[1];
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
    vector<vi> a(n, vi(2));
    for(int i = 0; i < n; i++)
        cin>>a[i][0]>>a[i][1];

    memset(f, 0, sizeof f);   
    memset(cnt, 0, sizeof cnt);

    for(const vi& v : a)
        f[v[0]]++;

    sort(a.begin(), a.end(), comp);

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j +=i)
            cnt[i] += f[j];
        cnt[i]--;
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        if(a[i][1] >= a[0][1] * 2)
            break;

        int buy = min(cnt[a[i][0]], k / a[i][1]);
        res += buy * 2; // cur with mul
        k -= buy * a[i][1];
    }
    
    cout<<res + k / a[0][1];
    return 0;
}

// 3 19
// 1 6
// 2 4
// 3 5