#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    a[0] = a[1];

    vi u;
    int k = 1;
    for(int i = 1; i <= (int)1e8; i+= k){
        u.push_back(i);
        k++;
    }

    int res = 0, sz = u.size(), tmp = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] < a[i - 1]) tmp = 0;

        int l = 0, r = sz - 1;
        bool ok = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(u[mid] == a[i]){
                ok = 1;
                tmp++;
                break;
            }
            else if(u[mid] < a[i]) l = mid + 1;
            else r = mid - 1;
        }
        if(!ok) tmp = 0;

        res = max(res, tmp);
    }
    cout<<res;
    return 0;
}