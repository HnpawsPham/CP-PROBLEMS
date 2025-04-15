#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

class BIT{
    private:
        vector<int> t;
        int sz;
    public:
        BIT(int n){
            sz = n + 2;
            t.resize(sz, 0);
        }
        
        void update(int i, int val){
            i++;
            while(i < sz){
                t[i] += val;
                i += (i & -i);
            }
            return;
        }

        int query(int i){
            i++;
            int res = 0;

            while(i > 0){
                res += t[i];
                i -= (i & -i);
            }
            return res;
        }
};

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    
    BIT fw(n);
    unordered_map<int, int> mp;
    ll res = 0;

    for(int i = 0; i < n; i++) mp[a[i]] = i;

    for(int i = 0; i < n; i++){
        int pos = mp[b[i]];

        int l = fw.query(pos - 1);
        int r = (n - 1 - pos) - (i - l);

        res += 1LL * l * r;
        fw.update(pos, 1);
    }
    cout<<res;
    return 0;
}