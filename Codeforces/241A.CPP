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

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int d[n], w[n];
    for(int i = 0; i < n; i++) cin>>d[i];
    for(int i = 0; i < n; i++) cin>>w[i];

    int sum = 0, t = 0, maxx = 0;
    for(int i = 0; i < n; i++){
        sum += w[i];
        maxx = max(maxx, w[i]);

        // while(sum < d[i]){
        //     sum += maxx;
        //     t += k;
        // }
        // sum -= d[i];
        if(sum < d[i]){
            int tmp = (d[i] - sum + maxx - 1) / maxx;
            t += k * tmp;
            sum += tmp * maxx;
        }
        
        sum -= d[i];
        t += d[i];
    }
    cout<<t;
    return 0;
}