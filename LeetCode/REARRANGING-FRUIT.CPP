#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    int minn = 1e9 + 1;
    unordered_map<int, int> mp;
    for(const int& x : a) {
        mp[x]++;
        minn = min(x, minn);
    }
    for(const int& x : b) {
        mp[x]--;
        minn = min(minn, x);
    }

    ll sum = 0;
    vi add;
    for(auto[x, cnt] : mp){
        if(cnt == 0) continue;
        if(cnt % 2) return cout<<-1, 0;

        for(int i = 0; i < cnt/2; i++)
            add.push_back(x);
    }
    sort(add.begin(), add.end());
    
    for(const int& x : add)
        sum += min(x, 2 * minn);
    
    cout<<sum;
    return 0;
}