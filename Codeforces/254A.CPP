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

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    n *= 2;

    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    map<int, vi> mp;
    for(int i = 0; i < n; i++)
        mp[a[i]].push_back(i + 1);

    for(const auto&x : mp)
        if(x.se.size() % 2) return cout<<-1, 0;
    
    for(auto& [_, v] : mp){
        while(!v.empty()){
            cout<<v.back()<<" ";
            v.pop_back();
            cout<<v.back()<<el;
            v.pop_back();
        }
    }
    return 0;
}