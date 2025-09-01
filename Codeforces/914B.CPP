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

    int n;
    cin>>n;
    int a[n], cnt[maxn] = {0};
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }

    bool ok = 0;
    for(int x : cnt) 
        if(x % 2) ok = 1;

    if(!ok) cout<<"Agasa";
    else cout<<"Conan";
    return 0;
}