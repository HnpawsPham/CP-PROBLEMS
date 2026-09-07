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

    int n, q;
    cin>>n>>q;
    int a[n];
    for(int i = 1; i < n; i++) cin>>a[i];

    int rank[n];
    rank[0] = 1;
    for(int i = 1; i < n; i++){
        rank[i] = a[i] + 1;
        for(int j = i - 1; j >= 0; j--)
            if(rank[j] >= rank[i])
                rank[j]++;
    }
    while(q--){
        int x;
        cin>>x;
        cout<<rank[x - 1]<<el;
    }
    return 0;
}