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
    int a[n], cnt[n + 1] = {0};
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(a[i] != -1) cnt[a[i]]++;
    }
    vi miss;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] > 1) return cout<<"No", 0;
        if(cnt[i] == 0) miss.push_back(i);
    }

    int j = 0;
    for(int i = 0; i < n; i++)
        if(a[i] == -1) a[i] = miss[j++];

    cout<<"Yes"<<el;
    for(int x : a) cout<<x<<" ";
    return 0;
}