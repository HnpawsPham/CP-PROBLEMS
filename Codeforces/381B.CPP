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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    vi b, res = {a[0]};
    int last = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] > a[i - 1]){
            res.push_back(a[i]);
            last = a[i];
        }
        else b.push_back(a[i]);

    b.push_back(last);
    int m = b.size();
    for(int i = m - 2; i >= 0; i--)
        if(b[i] < b[i + 1]) 
            res.push_back(b[i]);

    cout<<res.size()<<el;
    for(const int& x : res) cout<<x<<" ";
    return 0;
}