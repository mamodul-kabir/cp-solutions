
/*

              Note:             *sometimes it is better to use map and sets. In this problem the distinct values are scattered in a range. Set and map in this case. 
                                *defining a separate vector for each "decompose" function call caused TLE.
              Link:             https://oj.uz/problem/view/IOI11_race        

*/
#include "race.h"
 
#include <bits/stdc++.h>
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end()
#define pii pair<ll,ll>
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mxr = 200005;
const ll big = 2000000999;
 
ll n,k,path[1000011],mac,ans = big;
vector<vector<pii>> g;
bitset<mxr> ded;
vector<ll> sz(mxr); 
 
void dfs(ll v,ll p){
  sz[v] = 1;
  for(pii r: g[v]){
    if(r.F == p || ded[r.F]) continue; 
    dfs(r.F,v); 
    sz[v] += sz[r.F]; 
  }
  return; 
}
 
ll fcen(ll v,ll p,ll lim){
  for(pii r: g[v]){
    if(r.F == p || ded[r.F]) continue;
    if(sz[r.F] > lim) return fcen(r.F,v,lim);
  }
  return v;
}
 
void fil(ll v,ll p,ll cost,ll dep,unordered_map<ll,ll> &dis){
  if(cost > k) return;
  ans = min(ans,dep + path[k - cost]); 
  dis[cost] = dis.count(cost) ? min(dis[cost],dep) : dep; 
  for(pii r: g[v]){
    if(r.F == p || ded[r.F]) continue;
    fil(r.F,v,cost + r.S,dep+1,dis);
  }
  return;
}
 
void decompose(ll v){
  dfs(v,-1);
  ll lim = (sz[v]/2);
  ll cen = fcen(v,-1,lim);  
  ded[cen] = 1;
  unordered_set<ll> cum;  
  for(pii r: g[cen]){
    if(ded[r.F]) continue; 
    unordered_map<ll,ll> dis; 
    fil(r.F,cen,r.S,1,dis);
    for(pii x: dis){
      cum.insert(x.F); 
      path[x.F] = min(x.S,path[x.F]); 
    }
  } 
  ans = min(ans,path[k]); 
  for(ll i : cum) path[i] = big;
  for(pii r: g[cen]){
    if(!ded[r.F]) decompose(r.F);
  }
}
 
int best_path(int N, int K, int H[][2], int L[])
{
  n = N;
  k = K;
  g.assign(n,{});
  for(ll i = 1; i < n; i++){
    ll a = H[i-1][0], b = H[i-1][1], c = L[i-1]; 
    g[a].pb({b,c});
    g[b].pb({a,c});
  }
  for(ll i = 0; i <= 1000010; i++) path[i] = big; 
  decompose(0);
  return ans == big ? -1 : ans;
}
