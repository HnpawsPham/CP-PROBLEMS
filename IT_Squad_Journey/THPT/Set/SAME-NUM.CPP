#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    vector<ll> res;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        if(m < n){
            swap(n,m);
        }

        set<ll> a, b;

        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;

            a.insert(x);
        }

        for (int i = 0; i < m; i++)
        {
            ll x;
            cin >> x;

            b.insert(x);
        }

        for(auto x : a){
            if(b.count(x) == 0){
                res.push_back(x);
            }
        }
    }

    for(auto x : res){
        cout<<x<<" ";
    }
    cout<<endl;
    
    if(res.size() == 0){
        cout<<"NOT FOUND"<<endl;
    }
}