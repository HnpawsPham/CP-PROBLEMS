#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n, k;

bool valid(int x, int y){
    return (x % k == y % k) || (x % k == k - (y % k));
}

string sol(){
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    unordered_map<int, int> mpa, mpb;
    unordered_set<int> mod;

    for(int i = 0; i < n; i++){
        mpa[a[i] % k]++;
        mpb[b[i] % k]++;
        mod.insert(a[i] % k);
        mod.insert(k - (a[i] % k));
        mod.insert(b[i] % k);
        mod.insert(k - (b[i] % k));
    }

    unordered_set<bool> check;

    for(int x : mod){
        if(check.count(x));
        int x1 = k - x;

        int cnta = mpa[x];
        int cntb = mpb[x];

        if(x != x1){
            cnta += mpa[x1];
            cntb += mpb[x1];
        }

        if(cnta != cntb) return "NO";
        check.insert(x);
        check.insert(x1);
    }
    return "YES";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<sol()<<el;
    }

    return 0;
}