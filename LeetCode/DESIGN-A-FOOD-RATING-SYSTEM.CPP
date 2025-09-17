#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define pis pair<int, string>


struct comp {
    bool operator()(const pis &a, const pis &b) const {
        if (a.fi != b.fi) return a.fi > b.fi;
        return a.se < b.se;
    }
};

class FoodRater {
public:
    unordered_map<string, pis> info;
    unordered_map<string, set<pis, comp>> mp;

    FoodRater(vector<string>& food, vector<string>& cuisine, vector<int>& rating) {
        int n = food.size();
        for(int i = 0; i < n; i++){
            mp[cuisine[i]].insert({rating[i], food[i]});
            info[food[i]] = {rating[i], cuisine[i]};
        }
        return;
    }
    
    void update(string food, int val) {
        auto [x, type] = info[food];
        mp[type].erase({x, food});
        mp[type].insert({val, food});
        info[food].fi = val;
        return;
    }
    
    string query(string cuisine) {
        return mp[cuisine].begin()->se;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}