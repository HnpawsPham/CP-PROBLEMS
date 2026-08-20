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
    int p[n];
    for(int i = 0; i < n; i++) cin>>p[i];

    vector<int> a = {p[0]}, b = {p[1]};
    for(int i = 2; i < n; i++){
        if(a.back() > b.back())
            a.push_back(p[i]);
        else b.push_back(p[i]);
    }
    
    for(const int& x : a) cout<<x<<" ";
    for(const int& x : b) cout<<x<<" ";
    return 0;
}