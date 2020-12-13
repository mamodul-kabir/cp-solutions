/*
    
    Note        :      	1. map each distinct salary 
						2. save their occurrence in a segment tree by their range. 
						3. when there is a mutation, decrease the previous value by one and increase the current value by one.
						4. for range query output the number of salaries in the range.
 
    Link        :       https://cses.fi/problemset/task/1144
 
    Boka hoye gelum...
*/
#include "bits/stdc++.h"
 
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
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 250000;
 
 
ll ar[si],str[si * 16],fre[4 * si];
 
vector<pii> tem;
vector<pair<char,pii>> que;
 
unordered_map<ll,ll> rec,ind;
 
 
void make(ll a,ll b,ll node){
	if(a == b){
		str[node] = fre[a];
		return;
	}
	ll mid = a + (b - a)/2;
	make(a,mid,2 * node);
	make(mid + 1,b,(2 * node) + 1);
	str[node] = str[node * 2] + str[(2 * node) + 1];
	return;
}
 
void updt(ll a,ll b,ll i,ll node,ll val){
	if(a == b){
		str[node] += val;
		return;
	}
	ll mid = a + ( b - a)/2;
	if(i <= mid) updt(a,mid,i,node * 2,val);
	else updt(mid + 1,b,i,(2 * node) + 1,val);
	str[node] = str[node * 2] + str[(2 * node) + 1];
	return;
}
 
ll sum(ll a,ll b,ll i,ll j,ll node){
	if(i > b || j < a ) return 0;
	if(a >= i && b <= j) return str[node];
	ll mid = a + (b - a)/2;
	ll p1 = sum(a,mid,i,j,2 * node), p2 = sum(mid + 1,b,i,j,(2 * node) + 1);
	return p1 + p2;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
   	rec.reserve(524288);
	rec.max_load_factor(0.25);
	ind.reserve(524288);
	ind.max_load_factor(0.25);
 
    ll n,q; cin>>n>>q;
    for(ll i = 0; i < n; i++){
    	cin>>ar[i];
    	if(rec.count(ar[i])) rec[ar[i]] += 1;
    	else rec[ar[i]] = 1;
    }
    memset(fre,0,sizeof(fre));
    memset(str,0,sizeof(str));
    for(ll i = 0; i < q; i++){
    	char t; ll a,b; 
    	cin>>t>>a>>b;
    	que.pb({t,{a,b}});
    	if(!rec.count(b)) rec[b] = 0;
    	if(t == '?' && !rec.count(a)) rec[a] = 0;
    }
    ll p = 0;
    for(pii r: rec) tem.pb(r);
    sort(all(tem));
    for(pii r: tem){
    	ind[r.F] = p;
    	fre[p] = r.S;
    	p++;
    }
    make(0,p-1,1);
    for(auto k: que){
    	char t = k.F; ll a = k.S.F,b = k.S.S;
    	if(t == '!'){
    		a -= 1;
    		ll pre = ar[a],ai = ind[pre],bi = ind[b];
    		ar[a] = b;
    		updt(0,p-1,ai,1,-1);
    		updt(0,p-1,bi,1,1);
    	}else{
    		ll ai = ind[a],bi = ind[b];
    		cout<<sum(0,p-1,ai,bi,1) el;
    	}
    }
    return 0;
}