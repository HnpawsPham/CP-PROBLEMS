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

    vi res;
    int cntsmol = 0, cnt = 0;
    for(int i = 0; i < n; i++)
        if(a[i] < k) cntsmol++;
        else if(a[i] == k) cnt++;

    for(int i = 0; i < cnt; i++)
        res.push_back(i + cntsmol);

    for(const int& x : res)
        cout<<x<<" ";
    return 0;
}

// 5 2
// 1 2 5 2 3

// 5 3
// 1 2 5 2 3
