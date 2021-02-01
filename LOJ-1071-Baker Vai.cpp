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

int ar[100][100],mamo[100][100][100][2],n,m,pr[100][100];

ll get(int i,int j,int r){
	return j == 0 ? pr[i][r] : pr[i][r] - pr[i][j-1];
}

ll dp(int i,int p,int q,bool cn){
	if(i >= n || p >= m || q >= m || p > q) return -2000000000;
	if(p == q){
		if(p == m - 1 && i == n - 1) return ar[n-1][m-1];
		else return -2000000000;
	}
	if(mamo[i][p][q][cn] == -1){
		ll ans = 0;
		ans = max(ans,ar[i][q] + dp(i,p,q+1,0));
		ans = max(ans,ar[i][q] + ar[i][p] + dp(i+1,p,q,1));
		if(cn) for(int r = p; r < q; r++){
			ans = max(ans,get(i,p,r) + dp(i,r+1,q,0));
			ans = max(ans,get(i,p,r) + dp(i+1,r,q,1));
		}
		mamo[i][p][q][cn] = ans;
	}
	return mamo[i][p][q][cn];
}

ll do_dp(){
	memset(mamo,-1,sizeof(mamo));
	return dp(0,0,1,0);
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
    	cin>>n>>m;
    	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin>>ar[i][j];
    	for(int i = 0; i < n; i++){
    		pr[i][0] = ar[i][0];
    		for(int j = 1; j < m; j++){
    			pr[i][j] = ar[i][j];
    			pr[i][j] += pr[i][j-1];
    		}
    	}
    	ll ans = do_dp();
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
