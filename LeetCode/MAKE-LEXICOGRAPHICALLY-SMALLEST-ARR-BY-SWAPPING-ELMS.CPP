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

int n, lim;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>lim;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    pii b[n];
    for(int i = 0; i < n; i++)
        b[i] = {a[i], i};
    sort(b, b + n);

    int res[n];
    for(int i = 0; i < n; ){
        vi gr;
        int j = i;
        while(j == i || (j < n && b[j].fi - b[j - 1].fi <= lim))
            gr.push_back(b[j++].se);

        sort(gr.begin(), gr.end());
        int sz = gr.size();
        for(int x = 0; x < sz; x++)
            res[gr[x]] = b[i + x].fi;

        i = j;
    }

    for(const int& x : res)
        cout<<x<<" ";
    return 0;
}

// 5 2
// 1 5 3 9 8