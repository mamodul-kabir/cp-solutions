/*
 
    Note        :         I solved with Floyd Warshall algo and also mapped(not exactly) some nodes to decrease runtime. 

    Link        :      
 
    Keep it cool, that's how you do it. 
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
const ll si = 100005;

ll big = 200000000000000;

pii ar[105][105];
vector<int> node;
unordered_set<int> rec;

pii add(pii a,pii b){
    return {a.F + b.F, a.S + b.S};
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
    rec.max_load_factor(0.25);
    rec.reserve(1<<6);
    while(t--){
        ll v,e; cin>>v>>e;
        rec.clear();
        node.clear();
        for(int i = 0; i < 105; i++) for(int j = 0; j < 105; j++) ar[i][j] = i == j ? make_pair(0LL,0LL) : make_pair(big,big);
        for(int i = 0; i < e; i++){
            ll a,b,c,d; cin>>a>>b>>c>>d;
            rec.insert(a); rec.insert(b);
            ar[a][b] = ar[b][a] = min(ar[a][b],{c,d});
        }
        for(int r: rec) node.pb(r);
        int n = node.size();
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    ar[node[i]][node[j]] = min(ar[node[i]][node[j]],add(ar[node[i]][node[k]],ar[node[k]][node[j]]));
                }
            }
        }
        int q; cin>>q; 
        for(int i = 0; i < q; i++){
            int a,b; cin>>a>>b; 
            if(ar[a][b].F == big) cout<<"No Path.\n";
            else cout<<"Distance and time to reach destination is "<<ar[a][b].S<<" & "<<ar[a][b].F<<"." el;
        } 
        if(t) cout el;
    }
    return 0;
}
