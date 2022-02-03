/*
    
    Note        :         Divide and Conquer DP + normal segment tree
 
    Link        :         https://www.codechef.com/problems/CHEFAOR/
 
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


const ll mod = 100000007;
const ll si = 35005;
const ll inf = 7000; 

struct seg{
    vector<ll> str; 
    ll n; 
    ll fun(ll a,ll b){
        return a | b; 
    }
    void bld(ll a,ll b,ll node, ll *id){
        //cout<<a sp<<b el; 
        if(a == b){
            str[node] = id[a]; 
            return; 
        }
        ll lef = node * 2, mid = a + (b - a)/2;
        bld(a,mid,lef,id); 
        bld(mid+1,b,lef+1,id); 
        str[node] = fun(str[lef],str[lef+1]); 
        return; 
    }
    ll que(ll a,ll b,ll l,ll r,ll node){
        if(b < l || r < a) return 0; 
        if(a >= l && b <= r) return str[node]; 
        ll lef = node * 2, mid = a + (b - a)/2; 
        return fun(que(a,mid,l,r,lef),que(mid+1,b,l,r,lef+1)); 
    }
    seg(){
        str.resize(1,0); 
        return; 
    }
    void clr(ll x, ll *hehe){
        ll n = x;
        str.resize(4 * n,0); 
        bld(0,n - 1,1,hehe);  
        return; 
    }
}; 

seg sr; 
ll dp[2][5005],n,k,ar[5005],pr; 

void dnd(ll a,ll b,ll l,ll r){
    if(a > b || a < 0 || b >= n) return; 
    ll mid = a + (b - a)/2, rb = min(r,mid); 
    ll cur = 0; 
    if(rb < mid) cur = sr.que(0,n - 1, rb + 1, mid, 1); 
    pii ans = {-mod, r}; 
    for(ll i = rb; i >= l; i--){
        cur = cur | ar[i];
        ans = max(ans,{(i == 0 ? 0 : dp[pr][i - 1]) + cur,i});  
    }
    dp[pr ^ 1][mid] = ans.F; 
    dnd(a,mid - 1,l,ans.S); 
    dnd(mid + 1,b,ans.S,r); 
    return; 
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
    ll t; cin>>t; 
    while(t--){
        cin>>n>>k; 
        pr = 0; 
        for(ll i = 0; i < n; i++){
            cin>>ar[i];
            dp[0][i] = i == 0 ? ar[i] : (dp[0][i - 1] | ar[i]); 
        } 
        sr.clr(n,ar); 
        for(ll i = 1; i < k; i++){
            dnd(0, n - 1, 0, n - 1);   
            pr ^= 1; 
        }
        cout<<dp[pr][n - 1] el;
    }
    return 0;
}
