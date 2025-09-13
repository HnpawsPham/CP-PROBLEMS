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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vi v1, v2;
    for(int i = 1; i < n; i += 2)
        v1.push_back(a[i] - a[i - 1]);
        
    for(int i = 2; i < n; i += 2) 
        v2.push_back(a[i] - a[i - 1]);

    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());

    ll res[n + 1] = {0}, tmp[n + 1] = {0};
    int sz1 = v1.size(), sz2 = v2.size();

    int j = sz1 + 1;
    for(int i = 0; i < sz1; i++){
        if(v1[i] <= 0) {
            j = i + 1;
            break;
        }
        res[i + 1] = res[i] + v1[i];
    }
    for(int i = j; i <= n; i++) res[i] = res[i - 1];

    j = sz2 + 1;
    for(int i = 0; i < sz2; i++){
        if(v2[i] <= 0) {
            j = i + 1;
            break;
        }
        tmp[i + 1] = tmp[i] + v2[i];
    }
    for(int i = j; i <= n; i++) tmp[i] = tmp[i - 1];

    for(int i = 1;i <=n; i++) cout<<max(res[i], tmp[i])<<el;
    return 0;
}