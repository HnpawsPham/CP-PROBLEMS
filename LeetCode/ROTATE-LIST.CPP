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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(head == nullptr) return head;

    node tail = head;
    int n = 1;
    while(tail->next != nullptr){
        tail = tail->next;
        n++;
    }
    
    k %= n;
    if(k == 0) return head;
    tail->next = head;

    node cur = head;
    for(int i = 1; i < n - k; i++)
        cur = cur->next;

    node res = cur->next;
    cur->next = nullptr;
    return 0;
}