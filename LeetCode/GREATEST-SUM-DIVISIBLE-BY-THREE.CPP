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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int sum = 0;
    vi mod1, mod2;

    for(int x : a){
        sum += x;
        if(x % 3 == 1) mod1.push_back(x);
        else if(x % 3 == 2) mod2.push_back(x);
    }
    sort(mod1.begin(), mod1.end());
    sort(mod2.begin(), mod2.end());

    if(sum % 3 == 0) return cout<<sum, 0;
    int del1 = INT_MAX, del2 = INT_MAX;

    if(sum % 3 == 1){
        if(!mod1.empty()) del1 = mod1[0];
        if(mod2.size() >= 2) del2 = mod2[0] + mod2[1];
    }
    else{
        if(!mod2.empty()) del2 = mod2[0];
        if(mod1.size() >= 2) del1 = mod1[0] + mod1[1];
    }
    cout<<max(0, sum - min(del1, del2));
    return 0;
}

// 5
// 3 6 5 1 8

// 1
// 4