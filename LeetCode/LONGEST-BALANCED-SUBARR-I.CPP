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

    int res = 0;
    bool check[100005];
    for(int i = 0; i < n; i++){
        memset(check, 0, sizeof check);

        int cnto = 0, cnte = 0;
        for(int j = i; j < n; j++){
            if(!check[a[j]]){
                if(a[j] % 2) cnto++;
                else cnte++;
            }
            check[a[j]] = 1;
            // cout<<cnte<<" "<<cnto<<el;
            
            if(cnto > 0 && cnto == cnte)
                res = max(res, j - i + 1);
        }
    }
    cout<<res;
    return 0;
}

// 4
// 2 5 4 3

// 5
// 3 2 2 5 4

// 3
// 2 5 4

// 5
// 22 22 26 25 10