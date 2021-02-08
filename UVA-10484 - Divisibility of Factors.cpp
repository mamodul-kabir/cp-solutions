/*
 
    Note        :        OC
 
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
#define pii pair<ld,ld>
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 100005;

vector<ll> pri = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/    
    ll n,d; 
    while(cin>>n>>d){
        if(n == 0 && d == 0) break;
        vector<int> ar(25,1);
        for(int i = 0; i < 25; i++){
            while(d % pri[i] == 0){
                d /= pri[i];
                ar[i] -= 1;
            }
        }
        if(d > 1){
            cout<<0 el;
            continue;
        }
        for(int i = 2; i <= n; i++){
            int dum = i; 
            for(int r = 0; r < 25; r++){
                while(dum % pri[r] == 0){
                    dum /= pri[r];
                    ar[r] += 1;
                }
            }
        }
        bool np = false;
        for(int i = 0; i < 25; i++){
            if(ar[i] <= 0){
                np = 1;
                break;
            }
        }
        if(np){
            cout<<0 el; continue;
        }
        ll ans = 1;
        for(int i = 0; i < 25; i++) ans *= ar[i];
        cout<<ans el;
    }
    return 0;
}
