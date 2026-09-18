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
#define taskname "MIND"

int n, q;
const int maxn = 4e4 + 5;
const int oo = INT_MAX;
int a[maxn];

namespace sub2{
    void sol(){
        while(q--){
            int l, r;
            cin>>l>>r;
            int minn = oo;
            for(int i = l; i <= r; i++)
                for(int j = i + 1; j <= r; j++)
                    minn = min(minn, abs(a[i] - a[j]));
            cout<<minn<<el;
        }
    }
}

namespace sub4{
    void sol(){
        while(q--){
            int l, r;
            cin>>l>>r;
            vi b;
            for(int i = l; i <= r; i++)
                b.push_back(a[i]);
            sort(b.begin(), b.end());

            int minn = oo, sz = r - l + 1;
            for(int i = 1; i < sz; i++)
                minn = min(minn, a[i] - a[i - 1]);
            cout<<minn<<el;
        }
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];

    if(n <= 1000 && q <= 1000)
        sub2::sol();
    else sub4::sol();
    return 0;
}