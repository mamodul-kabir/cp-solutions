/*
 
    Note        :        bitmask dp-top down
                         *at first store each point k that comes into the way of line connecting points i and j. 
                         *for each mask, exclude the points that are covered when i and j points are connected and find the minimum. 
 
    Link        :      
 
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
#define pui pair<ll,pii> 
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = (1<<16);

pii ar[16];
ll mamo[si],pc[16][16],n;

bool sl(pii a,pii b,pii c){
	return ((b.S - a.S) * (c.F - b.F) == (b.F - a.F) * (c.S - b.S));
}

void ch(){
	memset(pc,0,sizeof(pc));
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = 0; k < n; k++) if(sl(ar[i],ar[j],ar[k])){
				pc[i][j] |= (1<<k);
			}
		}
	}
}

ll dp(ll mask){
	int bt = __builtin_popcount(mask);
	if(bt == 0) return 0;
	if(bt <= 2) return 1;
	if(mamo[mask] == 1001){
		for(int i = 0; i < n; i++) if(mask & (1<<i)){
			for(int j = i + 1; j < n; j++) if(mask & (1<<j)){
				mamo[mask] = min(mamo[mask],dp(mask ^ (mask & pc[i][j])) + 1);
			}
			break;
		}
	}
	return mamo[mask];
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
    	cin>>n; 
    	for(int i = 0; i < n; i++) cin>>ar[i].F>>ar[i].S;
    	ch();
    	ll lim = (1<<n);
    	for(int i = 0; i < lim; i++) mamo[i] = 1001;
    	ll ans = dp(lim-1);
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
