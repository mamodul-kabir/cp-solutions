/*
    
    Note        :            basic Divide and Conquer problem
 
    Link        :            https://acm.timus.ru/problem.aspx?space=1&num=1167
 
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

int n,k, ar[501], dp[2][501], pr = 0;   

int get(int a,int b){
    ll bla = ar[b] - (a == 0 ? 0 : ar[a - 1]), whi = b - a + 1 - bla;
    return bla * whi;  
}

void dnd(int a,int b,int l,int r){
    if(a > b) return; 
    int mid = a + (b - a)/2, rb = min(r,mid);
    pii ans = {mod,l};  
    for(int i = l; i <= rb; i++) ans = min(ans,{(i == 0 ? 0 : dp[pr][i - 1]) + get(i,mid), i}); 
    dp[pr ^ 1][mid] = ans.F; 
    dnd(a, mid - 1, l, ans.S); 
    dnd(mid + 1, b, ans.S, r); 
    return; 
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
    cin>>n>>k; memset(ar,0,sizeof(ar));  
    for(int i = 1; i <= n; i++){
        cin>>ar[i]; 
        ar[i] += ar[i - 1]; 
    }
    for(int i = 1; i <= n; i++) dp[0][i] = get(1,i); 
    for(int i = 1; i < k; i++){
        dnd(1, n, 1, n); 
        pr ^= 1; 
    }
    cout<<dp[pr][n] el; 
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
