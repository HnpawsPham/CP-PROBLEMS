#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

ll max(ll a, ll b){
    if(a>b){
        return a;
    }
    return b;
}

int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    cin.ignore();

    while (t--)
    {
        string str,num;
        getline(cin, str);

        stringstream ss(str);

        map<string, ll> m;

        while(ss >> num){
            m[num]++;
        }

        for(auto x : m){
            if(x.second > 1){
                cout<<x.first<<endl;
                break;
            }
        }
    }

    return 0;
}