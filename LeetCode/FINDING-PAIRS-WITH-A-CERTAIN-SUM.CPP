#include <bits/stdc++.h>
using namespace std;
#define el "\n"

class FindSumPairs {
private:
    int n, m;
    vector<int> a, b;
    unordered_map<int, int> mp;

public:
    FindSumPairs(vector<int>& a, vector<int>& b) {
        this->a = a;
        this->b = b;
        
        n = a.size();
        m = b.size(); 
        for(const int&x : b) mp[x]++;
    }
    
    void add(int i, int val) {
        mp[b[i]]--;
        b[i] += val;
        mp[b[i]]++;
        return;
    }
    
    int count(int tot) {
        int res = 0;
        for(int i = 0; i < n; i++)
            res += mp[tot - a[i]];

        return res;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}