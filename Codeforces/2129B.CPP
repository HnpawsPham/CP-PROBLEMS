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

int sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 0;
    for(int i = 0; i < n; i++){
        int cnt1 = 0, cnt2 = 0;

        for(int j = 0; j < i; j++)
            if(a[i] < a[j]) cnt1++;

        for(int j = i + 1; j < n; j++)
            if(a[i] < a[j]) cnt2++;

        res += min(cnt1, cnt2);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }

    return 0;
}

// 1
// 2
// 2 1
