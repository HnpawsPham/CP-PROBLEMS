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

int n;
const int oo = 1e9 + 3;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    pii a[n * 2];
    for(int i = 0; i < n; i++){
        cin>>a[i].fi;
        a[i].se = 1;
    }
    for(int i = 0; i < n; i++){
        cin>>a[i + n].fi;
        a[i + n].se = 2;
    }
    sort(a, a + n * 2);

    int cnt = 0;
    bool ok = 1;
    for(int i = 1; i < 2 * n; i++){
        if(!ok) ok = 1;
        else if(a[i].se != a[i - 1].se){
            cnt++;
            ok = 0;
        }
    }
    cout<<cnt;
    return 0;
}