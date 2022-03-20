/*
    
    Note        :            LIS w/ segment trees + DP with Knuth Optimization
 
    Link        :            https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4701
 
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
const ll oo = 3372036000000000;
const ll si = 1000005;

struct seg{
    ll str[4000020]; 
    ll n; 
    ll fun(ll a,ll b){
        return max(a,b); 
    }
    void bld(ll a,ll b,ll node, ll *id){
        //cout<<a sp<<b el; 
        if(a == b){
            str[node] = id[a]; 
            return; 
        }
        ll lef = node * 2, mid = a + (b - a)/2;
        bld(a,mid,lef,id); 
        bld(mid+1,b,lef+1,id); 
        str[node] = fun(str[lef],str[lef+1]); 
        return; 
    }
    ll que(ll a,ll b,ll l,ll r,ll node){
        if(b < l || r < a) return -1; 
        if(a >= l && b <= r) return str[node]; 
        ll lef = node * 2, mid = a + (b - a)/2; 
        return fun(que(a,mid,l,r,lef),que(mid+1,b,l,r,lef+1)); 
    }
    void upd(ll a,ll b,ll x,ll node, ll val){
        if(a == b){
            str[node] = val; 
            return; 
        }
        int mid = a + (b - a)/2,lef = node * 2; 
        if(x <= mid) upd(a,mid,x,lef,val); 
        else upd(mid+1,b,x,lef+1,val); 
        str[node] = fun(str[lef],str[lef+1]); 
        return; 
    }
    seg(){
        memset(str,-1,sizeof(str)); 
        return; 
    }
    void clr(){
        memset(str,-1,sizeof(str));   
        return; 
    }
};

seg heu;  
ll dp[1001][1001], cut[1001][1001], prf[1001]; 

ll get(int a,int b){
    return prf[b] - (a == 0 ? 0 : prf[a - 1]); 
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/ 
    int t; cin>>t; 
    for(int z = 1; z <= t; z++){
        memset(dp,0,sizeof(dp)); memset(cut,0,sizeof(cut)); 
        int n; cin>>n; 
        int ar[n], fin[n], tra[n - 1]; fill(fin,fin+n,1); 
        for(int i = 0; i < n; i++) cin>>ar[i]; heu.clr(); 
        for(int i = 0; i < n; i++){
            int cur = heu.que(0, 1000001,0, ar[i] - 1, 1); 
            fin[i] += cur + 1; cur++; 
            heu.upd(0,1000001,ar[i],1,cur); 
        } 
        heu.clr(); 
        //for(int r: fin) cout<<r sp; cout el; 
        for(int i = n - 1; i >= 0; i--){
            int cur = heu.que(0, 1000001,0, ar[i] - 1, 1); 
            fin[i] += ++cur; 
            heu.upd(0,1000001,ar[i],1,cur); 
        }   
        prf[0] = fin[0];
        for(int i = 1; i < n; i++) prf[i] = prf[i - 1] + fin[i];
        for(int i = 0; i < n; i++){
            dp[i][i] = 0;  
            cut[i][i] = i; 
        }
        for(int j = 2; j <= n; j++){
            for(int i = 0; i + j - 1 < n; i++){ 
                int end = i + j - 1, lb = cut[i][end - 1], rb = cut[i+1][end]; 
                pii ans = {mod,lb}; 
                for(int k = lb; k <= rb; k++) ans = min(ans,{dp[i][k] + (k == n - 1 ? 0 : dp[k + 1][end]), k}); 
                dp[i][end] = ans.F + get(i,end); 
                //cout<<i sp<<end sp<<ans.S sp<<ans.F sp<<get(i,end) el; 
                cut[i][end] = ans.S;
            }
        }
        //for(int r: fin) cout<<r sp; cout el; 
        cout<<"Case "<<z<<": "<<dp[0][n-1] el; 
    }
    return 0;
}
/*
    check for: 
        *missed a break, continue ? 
        *corner cases, n = 1?
        *overflow.
        *unnecessary logics.
        *impreciseness caused by double or long double. 
 
*/
