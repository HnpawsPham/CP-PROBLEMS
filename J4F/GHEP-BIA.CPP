#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

bool comp(const string& a, const string& b){
    return a + b > b + a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n, comp);

    for(const string& x : a) cout<<x;
    return 0;
}