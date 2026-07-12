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

void sol(){
    int n;
    cin>>n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    vi inc, dec;
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]){
            for(int j = 0; j < b[i] - a[i]; j++)
                inc.push_back(i + 1);
        }
        else if(a[i] > b[i]){
            for(int j = 0; j < a[i] - b[i]; j++)
                dec.push_back(i + 1);
        }
    }

    if(inc.size() != dec.size()){
        cout<<-1<<el;
        return;
    }

    int m = inc.size();
    cout<<m<<el;
    for(int i = 0; i < m; i++)
        cout<<dec[i]<<" "<<inc[i]<<el;
    return;
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
        sol();
    }
    return 0;
}