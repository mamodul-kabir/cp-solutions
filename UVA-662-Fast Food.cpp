/*
 
    Note        :        cpu-time: 0.030 ms
 
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

ll n,k,ar[205],pr[205],mamo[205][205][31];
pii be[205][205],nmn[31],rem[205][205][31];

ll get(int i,int j){
	if(i > j) return 0;
	return i == 0 ? pr[j] : pr[j] - pr[i-1];
}

void fil(int i,int j){
	be[i][j].F = oo;
	for(int r = i; r <= j; r++){
		 ll sm = (r - i + 1), bg = (j - r),tem = 0;
		 tem += abs(get(i,r) - (sm * ar[r])); 
		 tem += abs((bg * ar[r]) - get(r+1,j));
		 //cout<<r sp<<tem el;
		 if(tem < be[i][j].F){
		 	be[i][j].F = tem;
		 	be[i][j].S = r;
		 }
	}
	//cout<<be[i][j].F sp<<be[i][j].S el;
}

ll finmin(int i,int j){
	return be[i][j].F;
}

ll dp(int i,int j,int k){
	if(k == 1){
		rem[i][j][k] = {i,j};
		return finmin(i,j);
	}
	if(mamo[i][j][k] == -1){
		ll ans = oo;
		for(int r = i; r < j; r++){
			ll tem = finmin(i,r) + dp(r+1,j,k-1);
			if(tem < ans){
				ans = tem;
				rem[i][j][k] = {i,r};
			}
		}
		mamo[i][j][k] = ans;
	}
	return mamo[i][j][k];
}

void reb(int i,int j,int k){
	if(k == 1){
		nmn[k] = rem[i][j][k];
		return;
	}
	pii xx = rem[i][j][k];
	nmn[k] = xx;
	reb(xx.S+1,j,k-1);
	return;
}

void do_dp(int p){
	memset(mamo,-1,sizeof(mamo));
	ll res = dp(0,n-1,k);
	reb(0,n-1,k);
	cout<<"Chain "<<p el;
	for(int i = k,in = k - i + 1; i > 0; i--,in++){
		pii qq = nmn[i];
		int hot = be[qq.F][qq.S].S;
		cout<<"Depot "<<in<<" at restaurant "<<hot+1<<" serves ";
		if(qq.F == qq.S) cout<<"restaurant "<<qq.F+1 el;
		else cout<<"restaurants "<<qq.F+1 sp<<"to "<<qq.S+1 el;
	}
	cout<<"Total distance sum = "<<res el el;
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
    int t = 0;
    while(cin>>n>>k){
    	t++;
    	if(n == 0 && k == 0) break;
    	for(int i = 0; i < n; i++) cin>>ar[i];
    	pr[0] = ar[0];
    	for(int i = 1; i < n; i++){
    		pr[i] = ar[i];
    		pr[i] += pr[i-1];
    	}
    	for(int i = 0; i < n; i++){
    		for(int j = i; j < n; j++) fil(i,j);
    	}
    	do_dp(t);
    }
    return 0;
}
