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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d1, d2;
    cin>>n>>d1>>d2;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    vi d;
    for(int i = 0; i < n; i++)
        d.push_back(abs(a[i] - b[i]));
  
    int l = 0, r = *max_element(d.begin(), d.end()), mid, minx = r;
    int k = d1 + d2;

    while(l <= r){
        mid = l + (r - l) / 2;
        ll sum = 0;
        for(const int& x : d)
            sum += max(0, x - mid);

        if(sum <= k){
            minx = mid;
            r = mid - 1;
        }    
        else l = mid + 1;
    }

    for(int& x : d)
        if(x > minx){
            k -= (x - minx);
            x = minx;
        }

    for(int& x : d)
        if(x == minx && k > 0 && minx > 0){
            x--;
            k--;
        }
    
    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum += 1LL * d[i] * d[i];
    cout<<sum;
    return 0;
}

// 4 0 0
// 1 2 3 4
// 2 10 20 19

// 4 1 1
// 1 4 10 12
// 5 8 6 9