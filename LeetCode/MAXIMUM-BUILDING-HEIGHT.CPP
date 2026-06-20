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

const int oo = 1e9;
const int maxn = 1e5 + 1;

bool comp(const vi& a, const vi& b){
    return a[0] < b[0];
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vi> a(m, vi(2));
    for(int i = 0; i < m; i++)
        cin>>a[i][0]>>a[i][1];

    if(a.empty()) return cout<<n - 1, 0;

    a.push_back({1, 0});
    sort(a.begin(), a.end(), comp);
    m = a.size();

    for(int i = 1; i < m; i++)
        a[i][1] = min(a[i][1], a[i - 1][1] + a[i][0] - a[i - 1][0]);

    for(int i = m - 2; i > 0; i--)
        a[i][1] = min(a[i][1], a[i + 1][1] + a[i + 1][0] - a[i][0]);

    int maxx = 0;
    for(int i = 0; i < m - 1; i++)
        maxx = max(maxx, 
        max(a[i][1], a[i + 1][1]) + (a[i + 1][0] - a[i][0] - abs(a[i][1] - a[i + 1][1])) / 2);

    cout<<max(maxx, n - a.back()[0] + a.back()[1]);
    return 0;
}

// 5 2
// 2 1
// 4 1

// 10 4
// 5 3
// 2 5
// 7 4
// 10 3