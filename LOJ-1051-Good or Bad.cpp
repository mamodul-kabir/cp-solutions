/*
 
    Note        :        OC solution. 

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
const ll si = 101;

unordered_set<char> vow = {'A','E','I','O','U'};
string a; 
int mamo[51][51][51],n; 

int comb(int x,int y){
    if(x == 1 && y == 1) return 1;
    if(y == 0 && x == 0) return 0;
    return 2;
}

int dp(int i,int c,int v){
    if(c >= 5 || v >= 3) return 0;
    if(i == n) return 1;
    if(mamo[i][c][v] == -1){
        int ans;
        if(a[i] == '?') ans = comb(dp(i+1,0,v+1),dp(i+1,c+1,0));
        else ans = vow.count(a[i]) ? dp(i+1,0,v+1) : dp(i+1,c+1,0);
        //processing
        mamo[i][c][v] = ans;
    }
    return mamo[i][c][v];
}

int do_dp(){
    n = a.size();
    memset(mamo,-1,sizeof(mamo));
    return dp(0,0,0);
}

string fun(int a){
    if(a == 0) return "BAD";
    else if(a == 1) return "GOOD";
    else return "MIXED";
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
        cin>>a;
        string ans = fun(do_dp());
        cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
