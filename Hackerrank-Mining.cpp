/*
    
    Note        :       Not OC & not the full solution. Didn't notice D&C can be used to find the best option in range [i...j].  
 
    Link        :       https://www.hackerrank.com/contests/world-codesprint-5/challenges/mining/problem
 
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

const ll mod = 100000000000000007;
const ll si = 100005;
const ll inf = 7000; 

ll cost[5001][5001],n,k,dis[5001], we[5001], vpr[5001], mpr[5001], pr = 0, dp[2][5001],i; 

void fincost(ll a,ll b,ll l,ll r){
    if(a > b) return; 
    ll mid = a + (b - a)/2, rb = min(mid,r); 
    pii ans = {mod,-l}; 
    for(ll j = l; j <= rb; j++) ans = min(ans,{(dis[j] * (vpr[j - 1] - (i == 0 ? 0 : vpr[i - 1])) - (mpr[j - 1] - (i == 0 ? 0 : mpr[i - 1])) + (mpr[mid] - (j + 1 == 0 ? 0 : mpr[j])) - (dis[j] * (vpr[mid] - (j + 1 == 0 ? 0 : vpr[j])))),j});
    cost[i][mid] = ans.F; 
    if(a == b) return; 
    fincost(a, mid - 1, l, ans.S); 
    fincost(mid + 1, b, ans.S, r); 
    return;  
}

void dnd(ll a,ll b,ll l,ll r){
    if(a > b) return; 
    ll mid = a + (b - a)/2, rb = min(mid,r); 
    pii ans = {mod,l}; 
    for(ll j = l; j <= rb; j++){
        ans = min(ans,{(j == 0 ? 0 : dp[pr][j - 1]) + cost[j][mid], j}); 
    }
    dp[pr ^ 1][mid] = ans.F; 
    if(a == b) return; 
    dnd(a, mid - 1, l, ans.S); 
    dnd(mid + 1, b, ans.S, r); 
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
    cin>>n>>k; 
    vpr[0] = 0; mpr[0] = 0; 
    for(ll i = 0; i < n; i++){
        cin>>dis[i]>>we[i]; 
        cost[i][i] = 0; 
        if(i){
            vpr[i] = vpr[i - 1];
            mpr[i] = mpr[i - 1]; 
        } 
        vpr[i] += we[i]; 
        mpr[i] += (we[i] * dis[i]); 
    }
    for(i = 0; i < n; i++){
        fincost(i + 1, n - 1, i, n - 1); 
        dp[pr][i] = cost[0][i];
    } 
    for(ll i = 1; i < k; i++){
        dnd(0, n - 1, 0, n - 1);
        pr ^= 1; 
    } 
    cout<<dp[pr][n - 1] el; 
    return 0;
}
