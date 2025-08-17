#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    
    int p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    int res = 0;
    for(int i = 1; i <= n; i++){
        int suml = 0, sumr = 0;
        int r = i + 1;
        
        for(int l = i; l > 0; l--){
            suml += a[l];

            while(r <= n && sumr < suml)
                sumr += a[r++];

            if(suml == sumr) res = max(res, r - l);
        }
    }
    cout<<res;
    return 0;
}
