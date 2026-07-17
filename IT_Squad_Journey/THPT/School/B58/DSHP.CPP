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
#define taskname "DSHP"

int n, k;
const int maxn = 1e5 + 5;
int a[maxn];

namespace sub1{
    int sol(){
        for(int len = n - (n % 2); len > 1; len -= 2){
            for(int i = 0; i + len - 1 < n; i++){
                for(int x = 0; x < 3; x++){
                    for(int y = 0; y < 3; y++){
                        if(x == y) continue;
                        int cnt = 0;

                        for(int l = i; l <= i + len / 2 - 1; l++){
                            if(a[l] != x) cnt++;
                            if(cnt > k) break;
                        }

                        for(int r = i + len / 2; r <= i + len - 1; r++){
                            if(a[r] != y) cnt++;
                            if(cnt > k) break;
                        }

                        if(cnt <= k) return len;
                    }
                }
            }
        }
        return 0;
    }
};

namespace sub2{
    int p[maxn][3];

    void prepare(){
        memset(p, 0, sizeof p);
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < 3; j++){
                p[i][j] = p[i - 1][j];
                if(a[i - 1] == j) p[i][j]++;
            }
    }

    int sol(){
        prepare();

        for(int len = n - (n % 2); len > 1; len -= 2){
            for(int i = 0; i + len - 1 < n; i++){
                for(int x = 0; x < 3; x++){
                    for(int y = 0; y < 3; y++){
                        if(x == y) continue;

                        int j = i + len - 1;
                        int mid = (i + j) / 2;
                        if(mid - i + 1 - (p[mid + 1][x] - p[i][x])
                        + j - mid - (p[j + 1][y] - p[mid + 1][y]) <= k)
                            return len;
                    }
                }
            }
        }
        return 0;
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n <= 100) cout<<sub1::sol();
    else cout<<sub2::sol();
    return 0;
}