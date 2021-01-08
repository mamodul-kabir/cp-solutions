/*
 
    Note        :        I had to take a hint for an observation. If k >= 100, no solution exists. because the sum would not be divisible by the number. I failed to notice that and 
                         got an MLE. But a nice digit dp problem. 
                         
                         cpu-time   : 370ms

    Link        :       https://lightoj.com/problem/1068?problem=1068
 
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

int mamo[10][100][90][2],k,n;
vector<int> di;

int dp(int i,int re,int sum,bool f){
    if(i == n){
        if(re ==  0 && sum % k == 0) return 1;
        else return 0;
    }
    if(mamo[i][re][sum][f] == -1){
        int ans = 0,lim = f ? di[i] : 9;
        for(int r = 0; r <= lim; r++){
            int nre = ((re * 10) + r) % k,nsm = sum + r;
            bool nf = f && (r == lim);
            ans += dp(i+1,nre,nsm,nf);
        }
        mamo[i][re][sum][f] = ans;
    }
    return mamo[i][re][sum][f];
}

int do_dp(int a){
    if(k >= 100) return 0;
    di.clear();
    memset(mamo,-1,sizeof(mamo));
    while(a){
        di.pb(a%10); a /= 10;
    }
    reverse(all(di));
    n = di.size();
    return dp(0,0,0,1);
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
        int a,b; cin>>a>>b>>k;
        int ans = do_dp(b) - do_dp(a-1);
        cout<<"Case "<<T<<": "<<ans el;
    }
    return 0;
}
