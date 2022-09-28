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

int N = 200;

vector<vector<int>> g(N);
vector<bool> visited(N,0);

int dfs(int a, int go){

}

void solve(){
    int n,m;cin>>n>>m;
    int dish[n];
    int  oven[m];

    fore(i,0,n)cin>>dish[i];
    fore(i,0,m)cin>>oven[i];

    int curr_oven = 0;
    int waste = 0;

    fore(i,0,n){
        if(dish[i]>oven[curr_oven]){
            waste += oven[curr_oven];
            curr_oven++;
            i--;
        }else{
            oven[curr_oven] -= dish[i];    
        }
        //cout<<dish[i]<<" "<<oven[curr_oven]<<" "<<curr_oven<<"\n";
    }

    fore(i,curr_oven,m){
        waste+=oven[i];
    }

    cout<<waste<<"\n";
}

int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    //freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}

/*
Notes:

*/