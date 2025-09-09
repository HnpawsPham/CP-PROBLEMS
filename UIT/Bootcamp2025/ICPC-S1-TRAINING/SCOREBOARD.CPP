#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e5 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc, n;
    cin>>tc;
    while(tc--){
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++) cin>>a[i];
   
        int id = 1, tmp = 0, f = 0, res = 1;
        sort(a, a + n, greater<int>());
        for(int i = 1; i < n; i++){
            if(a[i] != a[i - 1]) {
                id = i + 1;
                tmp = 1;
            }
            else{
                tmp++;
                if(tmp > f) {
                    res = id;
                    f = tmp;
                }
            }
        }
        cout<<res<<el;
    }
    return 0;
}

// 6
// 4
// 100 90 90 80
// 5
// 5 4 3 2 1
// 6
// 50 50 40 40 40 30
// 7
// 10 20 20 10 30 30 30
// 8
// 100 90 100 80 70 70 70 60
// 5
// 5 5 5 5 5
