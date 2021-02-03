/*
 
    Note        :        
 
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
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 1<<15;

int n,mamo[1000][2],bld[1000][2],rnr[1000][2]; 

ll dp(int i,bool s){
	//cout<<i sp<<s el;
	if(i == n - 1) return bld[i][s];
	if(mamo[i][s] == -1){
		ll ans = min(dp(i+1,!s) + bld[i][s] + rnr[i][s],dp(i+1,s) + bld[i][s]);
		mamo[i][s] = ans;
		//cout<<i sp<<s sp<<ans el;
	} 
	return mamo[i][s];
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
    int T,s; cin>>T;
    for(int t = 1; t <= T; t++){
    	cin>>n;
    	for(int i = 0; i < n; i++) cin>>bld[i][0];
    	for(int i = 0; i < n; i++) cin>>bld[i][1];
    	for(int i = 1; i < n; i++) cin>>rnr[i-1][0];
    	for(int i = 1; i < n; i++) cin>>rnr[i-1][1];
    	memset(mamo,-1,sizeof(mamo));
    	ll ans = min(dp(0,0), dp(0,1));
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
