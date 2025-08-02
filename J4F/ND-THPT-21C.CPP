#include <bits/stdc++.h>
using namespace std;
#define el '\n'

struct Guest{
    int w, id;
    string s;

    Guest(int w1, int id1, string s1) : w(w1), id(id1), s(s1) {}

    bool operator<(const Guest& other) const{
        if(w == other.w) return id < other.id;
        return w < other.w; 
    }
};

int main(){
    freopen("TROCHOI.INP", "r", stdin);
    freopen("TROCHOI.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string s;
    vector<Guest> a;

    for(int i = 0; i < n; i++){
        cin>>s; 
        int cnt = 0;
        for(const char& x : s)
            cnt += ('0' <= x && x <= '9');

        Guest guest = {cnt, i, s};
        a.push_back(guest);
    }

    sort(a.begin(), a.end());
    for(const auto& x : a) cout<<x.s<<el;
    return 0;
}