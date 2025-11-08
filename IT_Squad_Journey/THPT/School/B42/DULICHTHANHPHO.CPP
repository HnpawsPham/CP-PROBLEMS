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

struct city{
    int pos, cnt = 0;
    ll sum = 0;
};

int n, k;
const int maxn = 4e5 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    queue<city> q;
    vector<vll> w(n, vll(k + 1, -1));

    for(int i = 0; i < n; i++){
        q.push({i, 0, a[i]});
        w[i][0] = a[i];
    }

    while(!q.empty()){
        auto [u, cnt, sum] = q.front();
        q.pop();

        for(int v = u + 1; v < n; v++){
            if(a[v] - a[u] == v - u){
                if(w[v][cnt] < sum + (ll)a[v]){
                    w[v][cnt] = sum + (ll)a[v];
                    q.push({v, cnt, sum + (ll)a[v]});
                }
            }
        }

        if(cnt < k){
            for(int v = u + 1; v < n; v++){
                if(w[v][cnt + 1] < sum + (ll)a[v]){
                    w[v][cnt + 1] = sum + (ll)a[v];
                    q.push({v, cnt + 1, sum + (ll)a[v]});
                }
            }
        }
    }

    ll res = 0;
    for(int i = 0; i < n; i++)
        res = max(res, w[i][k]);
    cout<<res;
    return 0;
}

// 8 1
// 1 2 3 4 6 6 8 9