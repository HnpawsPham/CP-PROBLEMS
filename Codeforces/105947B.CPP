#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n, m, k;

void sol(){
    int sz = n * m;
    int a[sz];
    for(int i = 0; i < sz; i++) cin>>a[i];

    k *= k;
    multiset<int> ms(a, a + k);
    auto mid = next(ms.begin(), k / 2 + 1);

    int j = 0;
    for(int i = k; ; i++){
        a[j + k / 2 + 1] = *mid;
        j++;
        if(i == sz) break;

        ms.insert(a[i]);

        if(a[i] < *mid) mid--;
        if(a[i - k] <= *mid) mid++;

        ms.erase(ms.lower_bound(a[i - k]));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout<<a[j + m * i]<<" ";
        cout<<el;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        sol();
    }

    return 0;
}

// 1
// 3 3 3
// 20 30 25
// 40 255 35
// 22 28 26