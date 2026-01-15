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

int r, c, n, m;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>r>>c>>n>>m;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i]; // ---
    for(int i = 0; i < m; i++) cin>>b[i]; // |

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int cnta = 1, cntb = 1, maxa = 1, maxb = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1] + 1) cnta++;
        else{
            maxa = max(maxa, cnta + 1);
            cnta = 1;
        }
    }

    for(int j = 1; j < m; j++){
        if(b[j] == b[j - 1] + 1) cntb++;
        else{
            maxb = max(maxb, cntb + 1);
            cntb = 1;
        }
    }
    maxa = max(maxa, cnta + 1);
    maxb = max(maxb, cntb + 1);

    if(maxa > maxb) swap(maxa, maxb);
    cout<<maxa * maxa;
    return 0;
}

// 2 1
// 2 1
// 2 3
// 2

// 1 1
// 1 1
// 2 
// 2

// 2 3
// 2 2
// 2 3
// 2 4