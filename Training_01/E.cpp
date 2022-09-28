#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin, cont.end
#define foreach(it, l) for(auto it = l.begin(); it != l.end; it++)
#define fore(i,a,b) for(ll i = a, almo5t = b; i<almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ENDL "\n"
typedef long long int ll;
using namespace std;

int N = 1000005;

vector<vector<ll>> tree(N, vector<ll>());
vector<bool> visited(N,0L);
vector<ll> p(N,0L);
vector<ll> anc_p(N,0L);
vector<ll> sbt_sum(N,0L);

ll dfs(int v){
    
    //int sum_sbt = 0;

    for(int son:tree[v]){
        sbt_sum[v] += dfs(son);
        //p[v] += anc_p[son];
        anc_p[v] += anc_p[son]; 
    }
    p[v] += anc_p[v];
    sbt_sum[v] += p[v];

    //cout<<v<<","<<tree[v].size()<<","<<p[v]<<","<<sbt_sum[v]<<"\n";

    return sbt_sum[v];
}

void solve(){
    int n,m,q;cin>>n>>m>>q;
    int jeff = 1;
    fore(i,0,n){
        int boss;cin>>boss;
        tree[boss].pb(i+1);
        if(boss == 0)jeff = i+1;
    }
    //cout<<n<<" "<<m<<" "<<q<<"\n";
    
    //int mi,e,v;cin>>mi>>e>>v;
    
    fore(i,0,m){
        ll mi,e,v;cin>>mi>>e>>v;
        //cout<<mi<<" "<<e<<" "<<v<<"\n";
        if(mi == 1){
            p[e] += v;
        }else{
            anc_p[e] += v;
        }
        //cout<<mi<<" "<<e<<" "<<v<<"\n";
    }
    
    
    dfs(jeff);
    
    fore(i,0,q){
        int ti,e;cin>>ti>>e;
        if(ti == 1){
            cout<<p[e]<<"\n";
        }else{
            cout<<sbt_sum[e]<<"\n";
        }
    }
}

int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}

/*
Notes:

*/