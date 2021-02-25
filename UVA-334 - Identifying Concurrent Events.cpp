/*
 
    Note        :         Fruteborce is da sweetest fruit. 
 
    Link        :      
 
 
*/
 
 
#include "bits/stdc++.h"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end()
#define pii pair<int,int>
#define vec vector<ll> 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 100000007;
const ll si = 10006;

bool ar[205][205];
unordered_map<string,int> rec;
unordered_map<int,string> rev; 

vector<pair<string,string>> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/    
    rec.reserve(1<<9); 
    rec.max_load_factor(0.25);
    rev.reserve(1<<9); 
    rev.max_load_factor(0.25);
    int nc,t = 0; 
    while(cin>>nc){
        if(!nc) break;
        int v = 0,nm,con = 0;
        memset(ar,0,sizeof(ar));
        ans.clear(); rec.clear(); rev.clear();
        for(int i = 0; i < nc; i++){
            int n; cin>>n; string ps = "",cs;
            for(int r = 0; r < n; r++){
                cin>>cs; 
                if(!rec.count(cs)){
                    rec[cs] = v;
                    ar[v][v] = 1;
                    rev[v++] = cs;
                }
                if(r){
                    int x = rec[ps], y = rec[cs];
                    ar[x][y] = 1;
                }
                ps = cs;
            }
        }
        cin>>nm; 
        for(int i = 0; i < nm; i++){
            string a,b; cin>>a>>b; 
            ar[rec[a]][rec[b]] = 1;
        }
        for(int k = 0; k < v; k++) for(int i = 0; i < v; i++) for(int j = 0; j < v; j++){
            ar[i][j] |= (ar[i][k] && ar[k][j]);
        }
        for(int i = 0; i < v; i++) for(int j = 0; j < v; j++){
            ar[i][j] |= ar[j][i];
            ar[j][i] |= ar[i][j];
        }
        for(int i = 0; i < v; i++) for(int j = i+1; j < v; j++){
            if(!ar[i][j]){
                con++;
                ans.pb({rev[i],rev[j]});
            }
        }
        if(!con) cout<<"Case "<<++t<<", no concurrent events." el;
        else{
            cout<<"Case "<<++t<<", "<<con<<" concurrent events:" el;
            for(int i = 0; i < con && i < 2; i++) cout<<"("<<ans[i].F<<","<<ans[i].S<<") ";
            cout el;
        }
    }
    return 0;
}
