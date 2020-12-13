/*
   YOU CAN'T TAKE HELP FROM EDITORIAL               .m.
   Link		: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1658
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
 
const ll mod = 1e9 + 7;
const ll mxr = 1e6 + 10;

vector<ll> coin,tab;
vector<pii> ans;
ll n,t;

void ini(){
	coin.clear(); tab.clear(); ans.clear();
	for(int i = 0; i < t; i++) ans.pb({-1,-1});
	return;
}

ll lcm(ll a,ll b){
	return (a * b)/__gcd(a,b);
}

void rec(int ind,int si, ll lc){
	if(si == 4){
		//cout<<lc el;
		for(int i = 0; i < t; i++){
			ll ex = (lc - (tab[i] % lc)) % lc,mn,mx;
			mn = tab[i] - (tab[i] % lc); mx = tab[i] + ex;
			ans[i].F = ans[i].F == -1 ? mn : max(mn,ans[i].F); ans[i].S = ans[i].S == -1 ? mx : min(mx,ans[i].S); 
		}
		return;
	}
	if(ind == n) return;
	ll ln = lcm(lc,coin[ind]);
	rec(ind+1,si+1,ln);
	rec(ind+1,si,lc);
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
    while(cin>>n>>t){
    	if(n == 0 && t == 0) break;
    	ini();
    	for(int i = 0; i < n; i++){
    		int x; cin>>x; coin.pb(x);
    	}
    	for(int i = 0; i < t; i++){
    		int x; cin>>x; tab.pb(x);
    	}
    	rec(0,0,(ll) 1);
    	for(pii r: ans) cout<<r.F sp<<r.S el;
    }
    return 0;
}