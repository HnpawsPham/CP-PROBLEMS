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
    int a[n][n - 1];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
            cin>>a[i][j];
    
    int cnt[105] = {0};
    int maxx = 0, fi;
    for(int i = 0; i < n; i++){
        cnt[a[i][0]]++;
        if(cnt[a[i][0]] > maxx){
            maxx = cnt[a[i][0]];
            fi = a[i][0];
        }
    }
    cout<<fi<<" ";
        
    for(int i = 0; i < n; i++)
        if(a[i][0] != fi){
            for(int j = 0; j < n - 1; j++)  
                cout<<a[i][j]<<" ";
            return;
        }
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
        cout<<el;
    }
    return 0;
}