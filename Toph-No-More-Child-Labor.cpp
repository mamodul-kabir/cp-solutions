/*
    
    Note        :       *maintain a mask of 10 bits.
                        *for each position find how many times a mask occurs and how many times the mask results in a good path. 
    
    Link        :       https://toph.co/p/no-more-child-labor
 
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
const ll lim = 1024; 
const ll oo = 337203600000000000;
const ll si = 100005;

bool is_palin(string a){
    int num = 0; 
    for(char r: a){
        num ^= (1<<(r - 'a')); 
    }
    return __builtin_popcount(num) <= 1; 
}

int n,m; 
ll res[41][41],mamo[41][41][1<<10],occ[41][41][1<<10]; 
vector<string> vec; 

int dp(int i,int j,int mask){
    if(i >= n || j >= m) return 0; 
    if(i == n - 1 && j == m - 1){
        int n_mask = mask ^ (1<<(vec[i][j] - 'a')); 
        return mamo[i][j][mask] = (__builtin_popcount(n_mask) <= 1); 
    }
    if(mamo[i][j][mask] == -1){
        int n_mask = mask ^ (1<<(vec[i][j] - 'a')),ans = 0;
        ans = (dp(i+1,j,n_mask) + dp(i,j + 1,n_mask)) % mod; 
        mamo[i][j][mask] = ans; 
    }
    return mamo[i][j][mask]; 
}

void get_res(){
    occ[0][0][0] = 1; 
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        int up = -1, lef = -1; 
        if(i > 0) up = (1<<(vec[i-1][j] - 'a')); 
        if(j > 0) lef = (1<<(vec[i][j-1] - 'a')); 
        for(int k = 0; k < lim; k++){
            if(i > 0) occ[i][j][up ^ k] = (occ[i][j][k ^ up] + occ[i-1][j][k]) % mod; 
            if(j > 0) occ[i][j][lef ^ k] = (occ[i][j][k ^ lef] + occ[i][j-1][k]) % mod; 
        }
        for(int k = 0; k < lim; k++){
            if(occ[i][j][k]) res[i][j] += (occ[i][j][k] * dp(i,j,k)) % mod; 
        }
        res[i][j] %= mod; 
    }
}

void case_2(){
    int rec[2][m],cnt[2][m],ans[2][m]; memset(rec,0,sizeof(rec));
    memset(cnt,0,sizeof(cnt)); memset(ans,0,sizeof(ans)); 
    int mask = 0;  
    for(int i = 0; i < m; i++){
        mask ^= (1<<(vec[0][i])); 
        rec[0][i] = mask; 
    } 
    mask = 0; 
    for(int i = m - 1; i >= 0; i--){
        mask ^= (1<<(vec[1][i])); 
        rec[1][i] = mask;
    }
    for(int i = 0; i < m; i++){
        int n_mask = (rec[0][i] ^ rec[1][i]); 
        cnt[0][i] = cnt[1][i] = (__builtin_popcount(n_mask) <= 1); 
    }
    ans[0][m-1] = cnt[0][m-1]; 
    for(int i = m - 2; i >= 0; i--) ans[0][i] = (ans[0][i+1] + cnt[0][i]); 
    ans[1][0] = cnt[1][0]; 
    for(int i = 1; i < m; i++) ans[1][i] = (ans[1][i-1] + cnt[1][i]); 
    for(int i = 0; i < n; i++,cout el) for(int j = 0; j < m; j++) cout<<ans[i][j] sp;
    return;   
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
    int t,cas = 0; cin>>t; 
    while(t--){
        cin>>n>>m;  
        vec.clear(); 
        for(int i = 0; i < n; i++){
            string notun; 
            cin>>notun; 
            vec.pb(notun); 
        }
        cout<<"Case "<<++cas<<": " el; 
        if(n == 1){
            int ans = is_palin(vec[0]) ? 1 : 0; 
            for(int i = 0; i < m; i++) cout<<ans sp; cout el; 
            continue; 
        }else if(n == 2){
            case_2(); 
            continue; 
        }
        memset(mamo,-1,sizeof(mamo)); memset(occ,0,sizeof(occ)); memset(res,0,sizeof(res)); 
        dp(0,0,0); 
        get_res(); 
        for(int i = 0; i < n; i++,cout el) for(int j = 0; j < m; j++) cout<<res[i][j] sp; 
    }
    return 0;
}
