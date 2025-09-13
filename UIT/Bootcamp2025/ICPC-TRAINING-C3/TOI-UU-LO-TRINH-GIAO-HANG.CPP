#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct mission{
    int g, pos, w;
};

bool comp(const mission& a, const mission& b){
    return a.g < b.g;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l;
    cin>>n>>l;
    mission a[n];
    for(int i = 0; i < n; i++) 
        cin>>a[i].g>>a[i].pos>>a[i].w;

    sort(a, a + n, comp);
    ll dp[n];
    for(int i = 0; i < n; i++){
        dp[i] = a[i].w;

        for(int j = 0; j < i; j++){
            int d = abs(a[i].pos - a[j].pos);

            if(d <= l && a[i].g - a[j].g >= d)
                dp[i] = max(dp[i], dp[j] + a[i].w);
        }
    }
    cout<<*max_element(dp, dp + n);
    return 0;
}