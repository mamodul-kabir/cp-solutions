/*
    
    Note        :           Super Messy Code. Easier Implementation is possible. Gotta see that. 
 
    Link        :           https://toph.co/p/subset-multiplication
 
    Boka hoye gelum...
*/

#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define pii pair<ll ,ll > 

 
using namespace std;
using ll = long long; 
using ld = long double;


const ll mod = 100000000007;
const ll si = 100005;
const ll inf = 7000; 

set<ll> ban = {23,13,17,19}; 
ll mamo[20][12][12][6][6][4][4][3][3][2][2],n; 
vector<vector<int>> man; 
vector<int> stuf = {2,3,5,7,11}, lim = {11,5,3,2,1}; 

ll dp(ll ind, ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h,ll i,ll j){
    if(ind == n) return (a == b && c == d && e == f && g == h && i == j) && (a || c || e || g || i); 
    if(mamo[ind][a][b][c][d][e][f][g][h][i][j] == -1){
        ll ans = dp(ind + 1,a,b,c,d,e,f,g,h,i,j); 
        ll ef = man[ind][0], es = man[ind][1], et = man[ind][2], eq = man[ind][3], ep = man[ind][4]; 
        if(a + ef <= lim[0] && c + es <= lim[1] && e + et <= lim[2] && g + eq <= lim[3] && i + ep <= lim[4]) ans += dp(ind+1,a + ef, b, c + es, d, e + et, f, g + eq, h, i + ep, j); 
        if(b + ef <= lim[0] && d + es <= lim[1] && f + et <= lim[2] && h + eq <= lim[3] && j + ep <= lim[4]) ans += dp(ind+1, a, b + ef, c, d + es, e, f + et, g, h + eq, i, j + ep); 
        mamo[ind][a][b][c][d][e][f][g][h][i][j] = ans;
        mamo[ind][b][a][d][c][f][e][h][g][j][i] = ans;  
    }
    return mamo[ind][a][b][c][d][e][f][g][h][i][j]; 
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
    ll t; cin>>t; 
    while(t--){
        man.clear(); 
        bool one = 0; 
        ll nn; cin>>n; nn = n;  
        for(ll i = 0; i < n; i++){
            ll x; cin>>x;
            if(ban.count(x)) nn--;
            else if(x == 1) one = 1, nn--;   
            else{
                vector<int> pow; 
                //cout<<x sp; 
                for(ll r: stuf){
                    ll cnt = 0; 
                    while(x % r == 0){
                        x /= r; 
                        cnt++; 
                    }
                    pow.pb(cnt); 
                }
                //for(ll r: pow) cout<<r sp; cout el; 
                man.pb(pow); 
            } 
        }
        n = nn; 
        memset(mamo,-1,sizeof(mamo)); 
        if(n == 0){
            cout<<0 el; 
            continue; 
        }
        ll ans = dp(0,0,0,0,0,0,0,0,0,0,0)/2; 
        if(one) ans *= 3; 
        cout<<ans el; 
    }
    return 0;
}
