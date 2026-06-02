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

int tc = 1;

string sol(){
    int n;
    cin>>n;

    int sus = 1;
    string ans;
    for(int i = 2; i <= n; i++){
        cout<<"? "<<sus<<" "<<i<<endl;
        cin>>ans;
        if(ans == "False!")
            sus = i;
    }

    for(int i = 1; i <= n; i++)
        if(i != sus){
            cout<<"? "<<sus<<" "<<i<<endl;
            cin>>ans;
            if(ans == "False!") 
                return "! FRIENDLY";

            cout<<"? "<<i<<" "<<sus<<endl;
            cin>>ans;
            if(ans == "True!") 
                return "! FRIENDLY";
        }
    return "! " + to_string(sus);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<endl;
    }
    return 0;
}