#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int m, n;
const int maxn = 1e5 + 5;
vector<vi> a;

bool comp_x(vi a, vi b){
    return a[0] < b[0];
}

bool comp_y(vi a, vi b){
    return a[1] < b[1];
}

bool check_Ox(){
    sort(a.begin(), a.end(), comp_x);
    int cnt = 0, last = a[0][2];

    for(vi v : a){
        int st = v[0], en = v[2];
        if(st >= last) cnt++;
        last = max(last, en);
    }

    return cnt >= 2;
}

bool check_Oy(){
    sort(a.begin(), a.end(), comp_y);
    int cnt = 0, last = a[0][3];

    for(vi v : a){
        int st = v[1], en = v[3];
        if(st >= last) cnt++;
        last = max(last, en);
    }

    return cnt >= 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;
    a.resize(n, vi(4));

    for(int i = 0; i < n; i++) 
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
    
    cout<<((check_Ox() || check_Oy()) ? "true" : "false");

    return 0;
}