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
/*
    Pr1: Remover digitos de un numero que no tiene 0's
    tal que obtengamos un número que no sea primo

    hints1:
    Si hay un número par ganamos

    3 -> 35, 33, 37 

    5 -> Si hay un 5 necesariamente hay un 3,5 o un 7
    así ponemo 35, 55 , 75

    7 

    9 -> Si hay un 9 ganamos

*/
const int N = 1e5 + 10;

vector<ll> t[N];
vector<ll> valst[2]; 
vector<ll> dp[2];

ll dfs(int xp,int x, int lr){
	if(dp[lr][x])return dp[lr][x];
	int sol = 0;
	for(auto h:t[x]){
        if(h==xp)continue;
        //cout<<"De: "<<x<<" Voy a:"<<h<<" Con: "<<lr<<"__________\n";
        ll v1 = dfs(x,h,0) + abs(valst[0][h] - valst[lr][x]);
        //cout<<"v1: "<<v1<<"\n";
        ll v2 = dfs(x,h,1) + abs(valst[1][h] - valst[lr][x]);
        //cout<<"v2: "<<v2<<"\n";

        sol += max(v1,v2);
        //cout<<"De: "<<x<<" Voy a:"<<h<<" Devulta: "<<sol<<"________\n";
    }
    dp[lr][x] = sol;
    return sol;
}


void solve(){
    int n;cin>>n;
    dp[0].clear();
    dp[1].clear();
    fore(i,0,n){
        dp[0].pb(0);
        dp[1].pb(0);
        valst[0].pb(0);
        valst[1].pb(0);
        t[i].clear();
    }

    fore(i,0,n){
        ll l,r; cin>>l>>r;
        valst[0][i] = l;
        valst[1][i] = r;
    }

    fore(i,0,n-1){
        int u,v;cin>>u>>v;
        u--;v--;
        t[u].pb(v);
        t[v].pb(u);
    }

    ll ans = max(dfs(0,0,0),dfs(0,0,1));
    cout<<ans<<"\n";
}

int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
