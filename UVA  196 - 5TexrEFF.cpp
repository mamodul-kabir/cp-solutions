/*
    
    Note        :   	1. I was getting TLE for using map then I used a formula to find the column number. 
			2. Number of row can have more than 1 digit. This gave one RE. 
			3. The General idea is to run a dfs and solve all the dependencies of a cell, ie. run dfs for the ones that 	have not been solved. Then solve this cell. 

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
#define pii pair<int,int> 


using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 100000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;


int rec(string st){
    int ans = 0,si = st.size();
    for(int i = 0; i <si ; i++){
        int in = (st[(si - i) - 1] - 'A') + 1;
        //cout<<in sp<<pow(26,i) el;
        ans += in * pow(26,i);
    }
    return ans - 1;
}

set<char> nms = {'1','2','3','4','5','6','7','8','9'};

int ar[18278][999]; 
bool cal[18278][999];
string prq[18278][999];


void calc(int x,int y){
    string st = prq[x][y];
    int tm = 0,s = 1, si = st.size(),a,b;
    for(int r = 1; r < si; r++){
        int x,y,q; 
        if(st[r] == '+'){
            string s1,s2;
            for(q = s; q < r; q++) if(nms.count(st[q])) break;
            s1 = string(st.begin() + s, st.begin() + q);
            s2 = string(st.begin() + q, st.begin() + r);
            istringstream(s2)>>a;
            s = r + 1;
            b = rec(s1);
            a -= 1;
            //cout<< q sp<<a sp<<b el;

        }else if(r == si - 1){
            string s1,s2;
            for(q = s; q <= r; q++) if(nms.count(st[q])) break;
            s1 = string(st.begin() + s,st.begin() + q);
            s2 = string(st.begin() + q,st.begin() + si);
            b = rec(s1);
            istringstream(s2)>>a;
            a -= 1;
            //cout<<a sp<<b el;
        }
        else continue;
        //cout<<a sp<<b el;
        if(!cal[a][b]) calc(a,b);
        tm += ar[a][b];
    }
    cal[x][y] = 1;
    ar[x][y] = tm;
}

void ndo(int n,int m){
    for(int i = 0; i <  n; i++) for(int j = 0; j < m; j++) cal[i][j] = 0;
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
    while(t--){
        int n,m; cin>>m>>n;
        ndo(n,m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                string st; cin>>st;
                if(st[0] != '='){
                    int x; 
                    istringstream(st)>>x;
                    ar[i][j] = x;
                    cal[i][j] = 1;
                }else prq[i][j] = st;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!cal[i][j]){
                    calc(i,j);
                }
            }
        }
        for(int i = 0; i < n; i++, cout el) for(int j = 0; j < m; j++){
            cout<<ar[i][j];
            if(j != m - 1) cout sp;
        } 
    }
    return 0;
}