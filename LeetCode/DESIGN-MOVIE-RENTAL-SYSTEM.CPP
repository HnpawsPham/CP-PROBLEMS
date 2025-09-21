#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define pii pair<int, int>
#define piii pair<int, pii>
#define vi vector<int>
#define fi first
#define se second

struct searchcomp{
    bool operator()(const pii& a, const pii& b) const{
        if(a.fi != b.fi) return a.fi < b.fi;
        return a.se < b.se;
    }
};

struct reportcomp{
    bool operator()(const piii& a, const piii& b) const {
        if (a.fi != b.fi) return a.fi < b.fi;
        if (a.se.fi != b.se.fi) return a.se.fi < b.se.fi;
        return a.se.se < b.se.se;
    }
};

class MovieRentingSystem {
public:
    map<pii, int> price;
    set<piii, reportcomp> rented;
    map<int, set<pii, searchcomp>> unrented;

    MovieRentingSystem(int n, vector<vi>& entries) {
        for(const auto& v : entries){
            int shop = v[0], movie = v[1], w = v[2];
            price[{shop, movie}] = w;
            unrented[movie].insert({w, shop});
        }
    }
    
    vi search(int movie) {
        vi res;
        int cnt = 5;
        for(auto it = unrented[movie].begin(); it != unrented[movie].end() && cnt; it++, cnt--) 
            res.push_back(it->se);
        return res;
    }
    
    void rent(int shop, int movie) {
        int w = price[{shop, movie}];
        unrented[movie].erase({w, shop});
        rented.insert({w, {shop, movie}});
    }
    
    void drop(int shop, int movie) {
        int w = price[{shop, movie}];
        rented.erase({w, {shop, movie}});
        unrented[movie].insert({w, shop});
    }
    
    vector<vi> report() {
        vector<vi> res;
        int cnt = 5;
        for(auto it = rented.begin(); it != rented.end() && cnt; it++, cnt--) 
            res.push_back({it->se.fi, it->se.se});
        return res;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}