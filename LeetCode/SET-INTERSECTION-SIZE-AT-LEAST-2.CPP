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

bool comp(const vi& a, const vi& b){
    if(a[0] != b[0]) return a[0] < b[0];
    return a[1] > b[1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vi> a(n, vi(2));
    for(int i = 0; i < n; i++) cin>>a[i][0]>>a[i][1];
    sort(a.begin(), a.end(), comp);

    int res = 0;
    vi d(n, 2);
    while(!a.empty()){
        vi cur = a.back();
        a.pop_back();

        for(int x = cur[0]; x < cur[0] + d.back(); x++){
            for(int i = 0; i < a.size(); i++)
                if(d[i] && a[i][1] >= x) d[i]--;

            res++;
        }
        d.pop_back();
    }
    cout<<res;
    return 0;
}

// 3
// 1 3
// 3 7
// 8 9

// 4
// 1 3
// 1 4
// 2 5
// 3 5