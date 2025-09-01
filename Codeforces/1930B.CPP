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
// int cnt = 0;

bool check(const vi& a){
    int n = a.size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j){
                if(a[i] % a[j]) continue;
                if(i < n - 1 && j < n - 1 && a[i + 1] % a[j + 1] == 0) return 0;
            }
    return 1;
}

void sol(){
    int n;
    cin>>n;

    vi res;
    for(int r = n, l = 1 + (n % 2); r > 0; r -= 2, l += 2){
        res.push_back(r);
        if(l <= n) res.push_back(l);
    }
    // if(check(res)) cnt++;
    for(const int& x : res) cout<<x<<" ";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    for(int i = 0; i < tc; i++){
        sol();
        cout<<el;
    }
    // if(cnt == tc) cout<<"ok";
    return 0;
}