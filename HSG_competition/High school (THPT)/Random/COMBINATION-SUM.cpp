#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, t;
const int maxn = 35;
int a[maxn];
vector<vector<int>> res;

void sol(int i, int sum, vector<int>& v){
    if(sum > t) return;
    if (i == n){
        if (sum == t) res.push_back(v);
        return;
    }

    for(int k = 0; sum + a[i] * k <= t; k++){

        for(int j = 0; j < k; j++)
            v.push_back(a[i]);
        
        sol(i + 1, sum + k * a[i], v);

        for(int j = 0; j < k; j++) v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>t;
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<int> v;
    sol(0, 0, v);

    for(vector<int> v : res){
        for(int x : v) cout<<x<<" ";
        cout<<el;
    }

    return 0;
}

class Solution {
    public:
        vector<vector<int>> res;
        void sol(int t, int n, int i, int sum, vector<int>& v, vector<int> a) {
            if (sum > t)
                return;
            if (i == n) {
                if (sum == t)
                    res.push_back(v);
                return;
            }
    
            for (int k = 0; sum + a[i] * k <= t; k++) {
    
                for (int j = 0; j < k; j++)
                    v.push_back(a[i]);
    
                sol(t, n, i + 1, sum + k * a[i], v, a);
    
                for (int j = 0; j < k; j++)
                    v.pop_back();
            }
        }
    
        vector<vector<int>> combinationSum(vector<int>& a, int t) {
            vector<int> v;
            sol(t, a.size(), 0, 0, v, a);
            return res;
        }
};