/*
    
    Note        :          Classical DP problem, but it's fully OC. That's why I added it. Also see the recursive solution ._.
    				CPU time	: 		0.089 ms. 

    Link        :          http://lightoj.com/volume_showproblem.php?problem=1231
    
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

const ll mod = 100000007;
const ll oo = 3372036000000000;

bool cmp(pii a,pii b){
	if(a.F == b.F) return a.S < b.S;
	return a.F < b.F;
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
    	int n,k; cin>>n>>k;
    	pii ar[n];
    	ll dp[k+1],tem[k+1];
    	for(int i = 0; i < n; i++) cin>>ar[i].F;
    	for(int i = 0; i < n; i++) cin>>ar[i].S;
    	sort(ar,ar+n,cmp);
    	memset(dp,0,sizeof(dp));
    	memset(tem,0,sizeof(tem));
    	dp[0] = 1;
    	for(int i = 0; i < n; i++){
    		for(int j = 1,lim = ar[i].S; j <= lim && (j * ar[i].F) <= k; j++) tem[j * ar[i].F] = 1;
    		for(int r = 1; r <= k; r++){
    			if(dp[r] > 0){
    				for(int j = 1,lim = ar[i].S; j <= lim && r + (j * ar[i].F) <= k; j++){
    					int ind = r + (j * ar[i].F);
    					tem[ind] = (dp[r] + tem[ind]) % mod;
    				}
    			}
    			dp[r] = (tem[r] + dp[r]) % mod;
    		}
    		memset(tem,0,sizeof(tem));
    	}
    	cout<<"Case "<<t<<": "<<dp[k] el;
	}	
    return 0;
}
