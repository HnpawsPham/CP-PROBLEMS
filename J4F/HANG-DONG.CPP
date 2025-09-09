#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, h;
const int maxn = 2e5 + 5;
const ll oo = 1e13;
int a[maxn];

ll check(int t){
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) cnt += (a[i] >= t);
        else cnt += (h - a[i] < t);
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>h;
    vi u, d;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        if(i % 2) u.push_back(a[i]);
        else d.push_back(a[i]);
    }
    sort(u.begin(), u.end());
    sort(d.begin(), d.end());

    ll res = oo;
    int cnt = 0;
    for(int i = 1; i <= h; i++){
        int tmp = d.end() - lower_bound(d.begin(), d.end(), i);
        tmp += u.end() - lower_bound(u.begin(), u.end(), h - i + 1);

        if(tmp < res){
            res = tmp;
            cnt = 1;
        }
        else if(tmp == res) cnt++;
    }
    cout<<res<<" "<<cnt;
    return 0;
}