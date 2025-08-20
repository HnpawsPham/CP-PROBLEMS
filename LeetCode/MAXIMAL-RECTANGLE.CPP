#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define vc vector<char>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vc> a(n, vc(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    vi b(m, 0);
    int res = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(int(a[i][j] - '0')) b[j]++;
            else b[j] = 0;
        }
        
        int l = m + 5;
        for(int r = 0; r < m; r++){
            if(b[r] > 0) {
                l = min(l, r);
                int h = n;
                
                for(int j = r; j >= l; j--){
                    h = min(h, b[j]);
                    res = max(res, h * (r - j + 1));
                }
            }
            else l = m + 5;
        }
    }  
    cout<<res;
    return 0;
}

// 4 5
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0