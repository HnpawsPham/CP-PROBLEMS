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
//#define taskname ""

class MyCalendarThree {
public:
    map<int, int> mp;
    int maxx;

    MyCalendarThree() {
        maxx = 0;
    }

    int book(int l, int r) {
        mp[l]++;
        mp[r]--;

        int sum = 0;
        for(const auto& [t, w] : mp){
            sum += w;
            maxx = max(maxx, sum);
        }
        return maxx;
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}