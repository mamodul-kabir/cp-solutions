/*
    
    Note        :           divide and conquer + prefix sum 
                            (used segment tree and got TLE at first) 
 
    Link        :           https://www.hackerrank.com/contests/ioi-2014-practice-contest-2/challenges/guardians-lunatics-ioi14/problem
 
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

const ll mod = 10000000000000007;
const ll si = 100005;
const ll inf = 7000; 



ll n,k,dp[2][8005],pr = 0, prf[8005]; 

ll get(ll a, ll b){
    return a == 0 ? prf[b] : prf[b] - prf[a - 1]; 
}

ll c(ll a,ll b){
    return (ll) (b - a + 1) * get(a,b); 
}


void dnd(ll a, ll b, ll l, ll r){
    if(a > b || a < 0 || b >= n) return; 
    ll mid = a + (b - a)/2, rb = min(mid,r); 
    pii ans = {mod,l};
    for(ll i = l; i <= rb; i++){
        ans = min(ans,{(i == 0 ? 0 : dp[pr][i - 1]) + c(i,mid), i}); 
    }
    dp[pr ^ 1][mid] = ans.F; 
    dnd(a, mid - 1, l, ans.S); 
    dnd(mid + 1, b, ans.S, r); 
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
    cin>>n>>k; 
    ll ar[n], cur = 0; 
    for(ll i = 0; i < n; i++){
        cin>>ar[i];
        cur += ar[i]; 
        prf[i] = cur; 
        dp[0][i] = (i + 1) * cur;  
    }   
    for(ll i = 1; i < k; i++){
        dnd(0, n - 1, 0, n - 1); 
        pr ^= 1; 
    }
    cout<<dp[pr][n - 1] el; 
    return 0;
}
