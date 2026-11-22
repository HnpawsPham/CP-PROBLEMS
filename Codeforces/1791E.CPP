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

ll sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a,a + n);

    ll sum = accumulate(a, a + n, 0LL);

    for(int i = 1; i < n; i+=2){
        if(a[i - 1] > 0) break;

        if(a[i] <= 0 && a[i - 1] <= 0){
            sum -= (a[i] + a[i - 1]); 
            sum += -a[i] - a[i - 1];
        }
        else if(a[i] >= 0 && a[i - 1] <= 0 && -a[i] - a[i - 1] > a[i] + a[i - 1]){
            sum -= (a[i] + a[i - 1]); 
            sum += -a[i] - a[i - 1];
        }
    }
    return sum;
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
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}