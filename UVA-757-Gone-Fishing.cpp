/*
 
    Note        :        cpu-time: 0.04 s
 
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
const ll si = (100);

int n,h,f[26],d[26],t[26],lim,mamo[25][965],rem[25][965],hue[26]; 

int dp(int i,int time){
	if(time >= lim || i == n) return 0;
	if(mamo[i][time] == -1){
		ll ans = 0,cur = 0;
		if(i < n - 1 && time + (t[i] * 5) <= lim) ans = dp(i+1,time + (t[i] * 5));
		for(int r = 0; time + ((r + 1) * 5) <= lim; r++){
			if(f[i] - (r * d[i]) <= 0 && i > 0) break;
			cur += max(0,f[i] - (r * d[i]));
			ll ntim = 1000, tem;
			if(i < n - 1) ntim = time + (5 * (r + 1)) + (t[i] * 5);
			tem = cur;
			if(ntim <= lim && i < n - 1) tem += dp(i+1,ntim);
			if(tem >= ans){
				//if(i == 0) cout<<tem sp<<r sp<<(5 * (r + 1)) el;
				ans = tem;
				rem[i][time] = (5 * (r + 1));
			}
		}
		//cout<<i sp<<time sp<<ans el;
		mamo[i][time] = ans;
	}
	return mamo[i][time];
}

void reb(int i,int time){
	if(i == n - 1){
		hue[i] = rem[i][time];
		return;
	}
	hue[i] = rem[i][time];
	//cout<<i sp<<time sp<<hue[i] el;
	if(time + hue[i] + (t[i] * 5) < lim) reb(i+1,time + hue[i] + (t[i] * 5));
	return;
}

void do_dp(){
	lim = h * 60;
	memset(mamo,-1,sizeof(mamo)); 
	memset(rem,0,sizeof(rem));
	memset(hue,0,sizeof(hue));
	ll res = dp(0,0);
	reb(0,0);
	for(int i = 0; i < n; i++){
		cout<<hue[i];
		if(i < n - 1) cout<<", ";
	}
	cout el<<"Number of fish expected: "<<res el;
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
    bool p = false;
    while(cin>>n){
    	if(!n) break;
    	else if(p) cout el;
    	p = 1;
    	cin>>h;
    	for(int i = 0; i < n; i++) cin>>f[i];
    	for(int i = 0; i < n; i++) cin>>d[i];
    	for(int i = 0; i < n-1; i++) cin>>t[i];
    	do_dp();
    }
    return 0;
}
