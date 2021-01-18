/*
 
    Note        :        

    Link        :      
 
    Boka hoye gelum...
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")


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
const ll si = (1<<16);

unordered_map<char,int> rec = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};
ll mamo[si][20],n,k,lim,q;
vector<ll> di;

ll dp(int mask,int rem){
	if(mask == lim - 1){
		return !(rem);
	}
	if(mamo[mask][rem] == -1){
		ll ans = 0;
		for(int i = 0; i < q; i++){
			if(!(mask & (1<<i))){
				int nre = ((rem * n) + di[i]) % k;
				ans += dp(mask | (1<<i),nre);
			}
		}
		mamo[mask][rem] = ans;
	}
	return mamo[mask][rem];
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
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
    	cin>>n>>k;
    	string st; cin>>st;
    	di.clear();
    	q = st.size();
    	memset(mamo,-1,sizeof(mamo));
    	for(int i = 0; i < q; i++){
    		di.pb(rec[st[i]]);
    	}
    	lim = (1<<q);
    	cout<<"Case "<<t<<": "<<dp(0,0) el;
    }
    return 0;
}
