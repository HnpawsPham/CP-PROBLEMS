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
    int a[n * m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i * m + j];

    if(n % 2) return cout<<n, 0;
    int mid = n * m / 2;
    bool ok = 1;

    while(n % 2 == 0 && ok){
        for(int i = 0; i < mid && ok; i++)
            if(a[i] != a[(n - i / m - 1) * m + i % m]) 
                ok = 0;
       
        if(ok){
            n /= 2;
            mid /= 2;
        }
    }
    cout<<n;
    return 0;
}