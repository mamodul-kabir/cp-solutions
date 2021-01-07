/*
 
    Note        :        NOT OC. I should've used 1D. But learnt a new thing. dont use extra dimensions unnecessarily. I needn't to consider subsegments, using 2d was a waste.
                         The TLE code was beautiful to be honest. I have to be careful in the future. 
                         
                         cpu-time : 245ms

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
int mamo[1001],n;

bool chp(int i,int j){
    int s = j - i + 1;
    for(int r = 0; r < s; r++){
        if(a[r + i] != a[j - r]) return false;
    }
    return true;
}

int dp(int i){
    if(i >= n) return 0;
    if(mamo[i] == -1){
        int ans = n - i + 13;
        for(int r = i; r < n; r++) if(chp(i,r))ans = min(ans,dp(r+1) + 1);
        mamo[i] = ans;
    }
    return mamo[i];
}

int do_dp(){
    memset(mamo,-1,sizeof(mamo));
    return dp(0);
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
