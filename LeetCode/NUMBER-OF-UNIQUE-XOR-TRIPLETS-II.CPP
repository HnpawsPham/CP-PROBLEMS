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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n ;i++) cin>>a[i];

    unordered_set<int> sum;
    for(const int& x: a)
        for(const int& y : a)
            sum.insert(x ^ y);

    bool check[2050];
    memset(check, 0, sizeof check);
    for(const int& x: a)
        for(const int& y : sum)
            check[x ^ y] = 1;
    
    int res = 0;
    for(int i = 0; i < 2050; i++)
        res += check[i];
    cout<<res;
    return 0;
}

// 2
// 1 3