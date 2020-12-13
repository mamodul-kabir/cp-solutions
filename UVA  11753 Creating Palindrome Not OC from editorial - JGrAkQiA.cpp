/*
    
    Note        :   Not OC. I had to check editorial. I solved it with an array of  10000 * 10000 which got
                    me a TLE. The new thing that I learnt from this problem is:
                        *   In a dp problem you if you increase dimension but the total size of the dimensions
                            is less than the previous total then it is sometimes ok to increase it. (replacing 
                            10000 * 10000 with 10000 * 21 * 21 in this case)
                        *   You can decrease a dimension by using the dependency of the dimension on another 
                            dimension. (dependence of J on I in this case).     

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
#define showp(x) <<showpoint<<setprecision(x)<<fixed<<
#define pii pair<int,int> 


using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const ll mxr = 1e6 + 10;

int n,k,dp[10005][21][21],ar[10005];

int rec(int i,int l,int r){
    if(dp[i][l][r] != -1) return dp[i][l][r];
    int j = n - i - 1 - l + r;
    /*  
                ^^ Important point to note here. Here (n - i - 1) is the palindromic position of the counterpart of
                i. L here shifts j to left and R shifts it to right. 
    */
    if(l + r > k) return 30;
    if(i >= j) return 0;
    if(ar[i] == ar[j]) return dp[i][l][r] = rec(i+1,l,r);
    return dp[i][l][r] = min(rec(i+1,l,r+1),rec(i,l+1,r)) + 1; 
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
    for(int T = 1; T <= t; T++,cout el){
        memset(dp,-1,sizeof(dp));
        cin>>n>>k;
        for(int i = 0; i < n; i++) cin>>ar[i];
        int ans = rec(0,0,0);
        cout<<"Case "<<T<<": ";
        if(ans > k) cout<<"Too difficult";
        else if(ans == 0) cout<<"Too easy";
        else cout<<ans;
    }
    return 0;
}