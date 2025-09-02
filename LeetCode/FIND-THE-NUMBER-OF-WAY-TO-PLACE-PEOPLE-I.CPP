#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

bool comp(const vi& a, const vi& b){
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vi> a(n, vi(2));
    for(int i = 0; i < n; i++) 
        cin>>a[i][0]>>a[i][1];
    sort(a.begin(), a.end(), comp);

    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        int prev = -1;
        for(int j = i + 1; j < n; j++){
            if(a[i][1] > a[j][1] && a[j][1] > prev){
                prev = a[j][1];
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}

// 3
// 1 1
// 2 2 
// 3 3 

// 3
// 3 1
// 1 3
// 1 1

// 3
// 6 2
// 4 4 
// 2 6