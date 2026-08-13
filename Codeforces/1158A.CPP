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
    int a[n], b[m];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += 1LL * m * 1LL * a[i];
    }
    for(int i = 0; i < m; i++) cin>>b[i];
    sort(a, a + n);
    
    int maxa = a[n - 1];
    int minb = *min_element(b, b + m);

    if(minb < maxa) return cout<<-1, 0;

    bool ok = 0;
    for(int i = 0; i < m; i++){
        sum += b[i] - maxa;
        ok |= (b[i] == maxa);
    }

    if(!ok) sum += maxa - a[n - 2];
    cout<<sum;
    return 0;
}