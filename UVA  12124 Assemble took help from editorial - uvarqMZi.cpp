/*
    
    Note        :       	1. Seperate the parts according to the types of the components. 
				2. Sort them by their quality and if their qualities are the same take the cheapest among the same quality. ( prune function does this)
				3. Select the least max among the different types of components. Let it be _ran
				4. If we can get the quality x then its also possible to get the qualities < x, so we can run a binary search from 0 to _ran to find the greatest value of x which is within budget. (void bs does that)
				5. For finding the cost of each of the builds, use binary search in each type of components and select the cheapest quality which is >= to the current minimal. (int fun does that). 


    Link        :		https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3276

    Boka hoye gelum...
*/
#include "bits/stdc++.h"
#include "bitset"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define showp(x) <<showpoint<<setprecision(x)<<fixed<<
#define pii pair<ll,ll> 


using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;

ll n,m,no,si,ran; 
unordered_map<string,ll> cty;
vector<vector<pii>> ar;

bool cmp(pii a,pii b){
	if(a.F == b.F){
		return a.S > b.S;
	}
	return a.F < b.F;
}

ll fun(ll i,ll x){
	ll l = 0, r = ar[i].size() - 1,ans;
	while(l <= r){
		ll mid = l + (r - l)/2;
		if(ar[i][mid].F >= x){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	return ar[i][ans].S;
}

bool valid(ll x){
	ll pri = 0;
	for(ll i = 0; i < si; i++){
		ll tem = fun(i,x);
		pri += tem;
	}
	return pri <= m;
}

void bs(ll r){
	ll l = 0,ans; 
	while(l <= r){
		ll mid = l + (r - l)/2;
		if(valid(mid)){
			ans = mid; 
			l = mid + 1;
		}else r = mid - 1;
	}
	cout<< ans el;
}

void prune(){
	ran = 2000000000;
	ll las;
	for(int i = 0; i < si; i++){
		sort(all(ar[i]),cmp);
		vector<pii> tem;
		las = ar[i].size() - 1;
		ran = min(ran,ar[i][las].F);
		ll rr = 2000000000;
		reverse(all(ar[i]));
		for(auto r: ar[i]){
			if(rr > r.S){
				rr = r.S; 
				tem.pb(r);
			}
		}
		ar[i].clear();
		reverse(all(tem));
		for(auto r : tem) ar[i].pb(r); 
	}
	return;
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
    int t; cin>>t;
    while(t--){
    	cin>>n>>m; 
    	cty.clear(); ar.clear(); no = 0;
    	for(ll i = 0; i < n; i++){
    		string ct,mt; ll pr,q,f; cin>>ct>>mt>>pr>>q;
    		if(!cty.count(ct)){
    			cty[ct] = no++;
    			ar.pb({});
    		}
    		f = cty[ct];
    		ar[f].pb({q,pr});
    	}
    	si = ar.size();
    	prune();
    	//for(int i = 0; i < si; i++, cout el) for(auto r: ar[i]) cout<<r.F sp<<r.S el;
    	//cout<<ran el;
    	bs(ran);
    }
    return 0;
}