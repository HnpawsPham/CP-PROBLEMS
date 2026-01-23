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
const int maxn = 3e5 + 5;
pii a[maxn];

bool check(int x){
    int y = 0, tmp = 0;

    for(int i = 0; i < m; i++){
        if(a[i].fi == x || a[i].se == x) continue;
        
        if(y == 0){ // set y thuoc {u, v}
            y = a[i].fi;
            tmp = a[i].se;
        }
        else{
            bool ok1 = (y == a[i].fi || y == a[i].se);
            bool ok2 = (tmp == a[i].fi || tmp == a[i].se);

            if(ok1 && ok2) continue;
            if(ok1) tmp = 0;
            else if(ok2){
                y = tmp;
                tmp = 0;
            }
            else return 0;
        }
    }
    return 1;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    // pii a[m];
    for(int i = 0; i < m; i++)
        cin>>a[i].fi>>a[i].se;

    if(n == 1) return cout<<"YES", 0;

    if(check(a[0].fi) || check(a[0].se))
        cout<<"YES";
    else cout<<"NO";
    return 0;
}