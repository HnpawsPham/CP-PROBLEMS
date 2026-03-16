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
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    set<int, greater<int>> s;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            s.insert(a[i][j]);

            int lim = min((n - i - 1) / 2, min(j, m - j - 1));

            for(int sz = 1; sz <= lim; sz++){
                int sum = 0;
                for(int x = 0; x <= sz; x++)
                    sum += a[i + x][j - x];
                
                for(int x = 1; x <= sz; x++)
                    sum += a[i + x][j + x];
           
                for(int x = 1; x <= sz; x++)
                    sum += a[i + sz + x][j - sz + x];
     
                for(int x = 1; x < sz; x++)
                    sum += a[i + sz + x][j + sz - x];

                if(sum) s.insert(sum);
            }
        }

    vi res;
    for(int i = 0; i < 3 && !s.empty(); i++){
        res.push_back(*s.begin());
        s.erase(s.begin());
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// 1 3
// 7 7 7

// 5 5
// 3 4 5 1 3
// 3 3 4 2 3
// 20 30 200 40 10
// 1 5 5 4 1
// 4 3 2 2 5