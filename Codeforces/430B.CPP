#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, k, x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>x;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 0;

    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1] && a[i] == x){
            int tmp = 2;
            int l, r, il = i - 2, ir = i + 1;

            while(1){
                if (il < 0 || ir == n || a[il] != a[ir]) break;

                for(int j = il; j >= 0; j--){
                    if(a[j] != a[il]) break; 
                    l = j;
                }

                for(int j = ir; j < n; j++){
                    if(a[j] != a[ir]) break;
                    r = j;
                }

                int d = il - l + r - ir + 2;
                if(d + (!tmp) >= 3) tmp += d;
                else break;

                il = l - 1; ir = r + 1;
            }
            res = max(res, tmp);
        }
    }
    cout<<res;
    return 0;
}