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

int tc = 1;
const int maxn = 3e5 + 5;
int a[maxn], maxx[maxn];

int sol(){
    int n;
    cin>>n;
    return maxx[n];
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    a[0] = 0;
    a[1] = 1;
    for(int i = 1; i <= maxn / 3; i++){
        a[2 * i] = a[i];
        a[2 * i + 1] = a[i] + a[i + 1];
    }

    maxx[0] = 0;
    for(int i = 1; i < maxn; i++)
        maxx[i] = max(a[i], maxx[i - 1]);

    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}