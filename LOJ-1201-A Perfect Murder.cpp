/*
 
    Note        :        My first OC dp on tree solution.
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
const ll si = (1<<16);

int n,m,mamo[1001][2]; 
vector<int> ar[1001];
bool vis[1001];

int dp(int i){
	if(!vis[i]){
		vis[i] = 1;
		mamo[i][0] = 0;
		mamo[i][1] = 1;
		for(int r: ar[i]){
			if(!vis[r]){
				dp(r);
				mamo[i][0] += max(mamo[r][0],mamo[r][1]);
				mamo[i][1] += mamo[r][0]; 
			}
		}
	}
	return max(mamo[i][0],mamo[i][1]);
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
    	cin>>n>>m; for(int i = 1; i <= n; i++) ar[i].clear();
    	for(int i = 0; i < m; i++){
    		int a,b; cin>>a>>b;
    		ar[a].pb(b); ar[b].pb(a);
    	}
    	int ans = 0;
    	memset(vis,false,sizeof(vis));
    	memset(mamo,-1,sizeof(mamo));
    	for(int i = 1; i <= n; i++) if(!vis[i]) ans += dp(i);
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
