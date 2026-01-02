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

int n, m;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    sort(b.begin(), b.end(), greater<int>());

    int cnt = 0;
    for(int x : b){
        if(sum > 0){
            sum -= x;
            cnt++;
        }
        else break;
    }
    cout<<cnt;
    return 0;
}

// 3 5
// 1 3 2
// 4 3 1 5 2