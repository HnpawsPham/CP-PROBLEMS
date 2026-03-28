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
//#define taskname "permute"

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
    vi a(n + 1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    vi b = a;
    int cnt = 0;
    do{
        vi tmp = b;
        for(int i = 1; i <= n; i++)
            b[i] = tmp[tmp[i]];

        for(int x : b) cout<<x<<" ";
        cout<<el;
        cnt++;
    } while(b != a);
    return 0;
}