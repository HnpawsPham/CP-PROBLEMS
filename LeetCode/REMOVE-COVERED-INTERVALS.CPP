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

bool comp(const vi&a, const vi& b){
    if(a[0] == b[0]) return a[1] > b[1];
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

    int n;
    cin>>n;
    vector<vi> a(n, vi(2));
    for(int i = 0; i < n; i++)
        cin>>a[i][0]>>a[i][1];

    sort(a.begin(), a.end(), comp);

    int cnt = a.size(), r = 0;
    for(const vi& v : a)
        if(v[1] <= r) cnt--;
        else r = v[1];

    cout<<cnt;
    return 0;
}

// 3
// 1 4
// 3 6
// 2 8

// 2
// 1 4
// 2 3