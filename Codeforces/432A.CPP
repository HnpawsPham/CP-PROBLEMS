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
    sort(a, a + n);

    int cnt = 0;
    for(int i = 2; i < n; i+=3)
        if(a[i] + k <= 5 && a[i - 1] + k <= 5 && a[i - 2] + k <= 5)
            cnt++;
        else break;
    cout<<cnt;
    return 0;
}