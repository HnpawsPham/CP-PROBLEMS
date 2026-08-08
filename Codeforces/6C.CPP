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

    int ta = 0, tb = 0, cnta = 0, cntb = 0;
    for(int i = 0, j = n - 1; i <= j; i++){
        ta += a[i];
        a[i] = 0;
        cnta++;

        while(j >= 0 && tb < ta){
            tb += a[j];
            cntb += a[j--] > 0;
        }
    }
    cout<<cnta<<" "<<cntb;
    return 0;
}