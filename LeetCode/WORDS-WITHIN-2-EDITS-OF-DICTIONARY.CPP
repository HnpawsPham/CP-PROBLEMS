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

    int n, m;
    cin>>n>>m;
    string a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    vector<string> res;
    int len = a[0].size();

    for(int i = 0; i < n; i++){
            bool ok = 1;
            for(int j = 0; j < m && ok; j++){
                int cnt = 0;
                for(int x = 0; x < len; x++){
                    if(a[i][x] != b[j][x]) cnt++;
                    if(cnt > 2) break;
                }
                if(cnt <= 2){
                    ok = 0;
                    res.push_back(a[i]);
                }
            }
        }

    for(const string& x : res) cout<<x<<" ";
    return 0;
}

// 4 3
// word note ants wood
// wood joke moat