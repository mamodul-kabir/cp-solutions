/*
    
    Note        :           persistent lazy segment tree + divide and conquer dp optimization
 
    Link        :           https://www.spoj.com/problems/NKLEAVES/
 
    Boka hoye gelum...
*/

#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define pii pair<ll ,ll > 

 
using namespace std;
using ll = long long; 
using ld = long double;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const ll mod = 100000000007;
const ll si = 100005;
const ll inf = 7000; 

struct node{
    node *left, *right;
    ll val, lz;
    node(ll a = 0, node *b = NULL, node *c = NULL, ll lazy = 0) : val(a), left(b), right(c), lz(lazy) {}
    node(node *helo){
        val = helo -> val; 
        lz = helo -> lz; 
        left = helo -> left; 
        right = helo -> right; 
    }
    void build(ll l, ll r){ 
        if(l == r) return; 
        left = new node(); 
        right = new node();
        ll mid = l + r >> 1;
        left -> build(l, mid);
        right -> build(mid+1, r);
    }
    void push(ll l,ll r){
        val += (r - l + 1) * lz; 
        if(l != r){
            left = new node(left); 
            right = new node(right); 
            left -> lz += lz; 
            right -> lz += lz; 
        }
        lz = 0; 
        return;  
    }
    node *rupd(ll a, ll b, ll l, ll r,ll del){
        if(b < l || a > r || l > r) return this; 
        if(lz) push(a,b); 
        if(l <= a && b <= r){
            node *ret = new node(val,left,right,0); 
            if(a != b){
                ret -> left = new node(left); 
                ret -> right = new node(right);
                ret -> left -> lz += del; 
                ret -> right -> lz += del; 
            }
            ret -> val += (b - a + 1) * del;
            return ret; 
        } 
        node *ret = new node(val,left,right,0);  
        ll mid = a + (b - a)/2;  
        ret -> left = left -> rupd(a,mid,l,r,del); 
        ret -> right = right -> rupd(mid+1,b,l,r,del); 
        ret -> val = ret -> left -> val + ret -> right -> val;
        return ret; 

    }  
    ll lque(ll a, ll b, ll l, ll r){
        //cout<<a sp<<b el; 
        if(b < l || a > r) return 0; 
        if(lz) push(a,b); 
        if(a >= l && b <= r) return val; 
        ll mid =  a + (b - a)/2; 
        return left -> lque(a,mid,l,r) + right -> lque(mid+1, b, l, r); 
    }
}*root[100005];

ll n,k,ar[1000005], dp[2][1000005], pr = 0; 

ll c(ll a, ll b){
    if(a >= b || a < 0 || b >= n) return 0; 
    return root[b] -> lque(0, n - 1, a, b); 
}

void dnd(ll a,ll b,ll l,ll r){
    if(a > b || a < 0 || b >= n) return; 
    pii ans = {mod,l}; 
    ll mid = a + (b - a)/2, rb = min(mid,r); 
    for(ll i = l; i <= rb; i++){
        ans = min(ans,{(i == 0 ? 0 : dp[pr][i - 1]) + c(i,mid), i});  
    }
    dp[pr ^ 1][mid] = ans.F;
    dnd(a,mid-1,l,ans.S); 
    dnd(mid+1,b,ans.S,r); 
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/ 
    root[0] = new node(); 
    cin>>n>>k; 
    root[0] -> build(0, n - 1); 
    ll cur = 0; 
    for(ll i = 0; i < n; i++){
        cin>>ar[i]; 
        ll pr = i == 0 ? 0 : i - 1; 
        root[i] = root[pr] -> rupd(0, n - 1, 0, i - 1, ar[i]); 
        cur += ar[i] * i; 
        dp[0][i] = cur; 
    } 
    //for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) cout<<i sp<<j sp<<c(i,j) el; cout el; 
    for(int i = 1; i < k; i++){
        dnd(0, n - 1, 0, n - 1); 
        pr ^= 1;   
    } 
    cout<<dp[pr][n - 1] el; 
    return 0;
}
