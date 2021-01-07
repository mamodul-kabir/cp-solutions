/*
 
    Note        :        I overly complicated it by making it 2d. It suffices to do it in 1D. 
                         Be careful in the future. 
                         
                         cpu-time : 1781ms (TLE).

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
 
const ll mod = 100000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 1000006;

string a;
int mamo[1001][1001],n;
bool pln[1001][1001];

int finp(){
    for(int i = 0; i < n; i++) pln[i][i] = 1, mamo[i][i] = 1;
    for(int i = 0; i < n - 1; i++) pln[i][i+1] = (a[i] == a[i+1]), mamo[i][i+1] = (a[i] == a[i+1]) ? 1 : 2;
    for(int i = 3; i <= n; i++){
    	for(int j = 0; j < n - i + 1; j++){
    		int k = j + i - 1;
    		pln[j][k] = (a[j] == a[k]) && pln[j+1][k-1];
    		if(pln[j][k]) mamo[j][k] = 1;
    		else{
    			mamo[j][k] = i + 2;
    			for(int r = j; r < k; r++) mamo[j][k] = min(mamo[j][k],mamo[j][r] + mamo[r+1][k]);
    		}
    	}
    }
    return mamo[0][n-1];
}

int do_dp(){
    //memset(pln,false,sizeof(pln));
    //memset(mamo,-1,sizeof(mamo));
    return finp();
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
    for(int T = 1; T <= t; T++){
        cin>>a; n = a.size();
        cout<<"Case "<<T<<": "<<do_dp() el;
        //cout<<n sp;
        //cout<<pln[0][1] sp<<pln[0][n-1] el; 
    }
    return 0;
}
