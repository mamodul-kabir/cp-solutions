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
const ll si = (1<<10);

int mamo[5001][5001],n,m; 
string a,b; 

int dp(int i,int j){
    if(i == n) return m - j;
    if(j == m) return n - i;
    if(mamo[i][j] == 200000000){
        int val = a[i] == b[j] ? 0 : 1,ans;
        ans = min(dp(i+1,j+1) + val,min(dp(i+1,j),dp(i,j+1)) + 1);
        mamo[i][j] = ans;
    }
    return mamo[i][j];
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
    cin>>a>>b;
    n = a.size(); m = b.size();
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) mamo[i][j] = 200000000;
    cout<<dp(0,0);
    return 0;
}
