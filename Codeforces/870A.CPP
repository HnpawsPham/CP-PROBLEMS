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

    int n, m;
    cin>>n>>m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    int check[10] = {0};
    for(int x : a) check[x]++;
    for(int x : b) check[x]++;

    for(int i = 1; i <= 9; i++)
        if(check[i] > 1) return cout<<i, 0;

    sort(a, a + n);
    sort(b, b + m);
    cout<<min(a[0], b[0])<<max(a[0], b[0]);
    return 0;
}