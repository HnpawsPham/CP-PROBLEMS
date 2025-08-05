#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

int n, k;
vector<vi> res;

void sol(int st, int sum, vi& v, const vi& a){
    if(sum == k){
        res.push_back(v);
        return;
    }

    for(int i = st; i < n; i++){
        if(i > st && a[i] == a[i - 1]) continue;

        if(sum + a[i] > k) break;

        v.push_back(a[i]);
        sol(i + 1, sum + a[i], v, a);
        v.pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a.begin(), a.end());
    vi tmp;
    sol(0, 0, tmp, a);

    for(vi& v : res){
        for(int x : v) cout<<x<<" ";
        cout<<el;
    }
    return 0;
}

// 7 8
// 10 1 2 7 6 1 5