#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int like = 0, dislike = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        like += (x == 1);
        dislike += (x == 2);

        if(x == 3){
            if(like >= dislike) like++;
            else dislike++;
        }
    }
    cout<<like<<" "<<dislike;
    return 0;
}