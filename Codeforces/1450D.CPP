#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;
const int maxn = 3e5 + 5;

void sol(){
    int n;
    cin>>n;
    int a[n + 1], cnt[n + 1] = {0};
    bool res[n + 1] = {0};
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }

    bool ok = 1;
    for(int i = 1; i <= n; i++)
        if(cnt[i] != 1){
            ok = 0;
            break;
        }
    res[1] = ok;
    res[n] = cnt[1];

    int l = 1, r = n;
    for(int i = 1; i < n; i++){
        if(cnt[i + 1] == 0 || --cnt[i]) break;
        if(a[l] == i) l++;
        else if(a[r] == i) r--;
        else break;
    }

    for(int i = r - l + 1; i < n; i++)
        res[i] = 1;

    for(int i = 1; i <= n; i++) cout<<res[i];
    cout<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--) sol();
    return 0;
}