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

    int inc = 1, dec = 1, maxx = 1;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i - 1]){
            inc++;
            dec = 1;
        }
        else if(a[i] < a[i - 1]){
            dec++;
            inc = 1;
        }
        else dec = inc = 1;
        maxx = max(maxx, max(dec, inc));
    }
    cout<<maxx;
    return 0;
}