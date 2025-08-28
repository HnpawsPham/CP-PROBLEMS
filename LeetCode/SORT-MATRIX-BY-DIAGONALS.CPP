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
    vector<vi> a(n, vi(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    vi st;
    for(int j = 1; j < n - 1; j++){
        int r = 0, c = j;
        while(r < n && c < n)
            st.push_back(a[r++][c++]);

        sort(st.begin(), st.end());

        r = 0; c = j;
        for(int x : st) a[r++][c++] = x;
        st.clear();
    }

    for(int i = n - 2; i >= 0; i--){
        int r = i, c = 0;
        while(r < n && c < n)
            st.push_back(a[r++][c++]);

        sort(st.begin(), st.end(), greater<int>());

        r = i; c = 0;
        for(int x : st) a[r++][c++] = x;
        st.clear();
    }

    for(auto v : a){
        cout<<el;
        for(int x : v) cout<<x<<" ";
    }
    return 0;
}

// 3 
// 1 7 3
// 9 8 2
// 4 5 6