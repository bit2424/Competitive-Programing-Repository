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

int N = 10000000;

vector<vector<int>> g(N);
vector<bool> visited(N,0);

vector<int> cr(N,-1);
vector<pair<int,int>> testP;

void init_sieve(){
    fore(i,2,N)if(cr[i]<0)for(ll j=1LL*i*i;j<N;j+=i)cr[j]=i;
}

ll pm(ll a, ll e, ll mod){
    ll r=1;
    while(e){
        if(e&1)r=(r*a)%mod;
        e>>=1;a=(a*a)%mod;
    }
    return r%mod;
}

void init_exp2(){
    fore(i,3,N){
        if(cr[i]<0){
            testP.pb({i,pm(2,i,i)});
            //cout<<testP.back().fst<<" "<<testP.back().snd<<"\n";
        }
    }
}

void solve(){
    int k;cin>>k;
    vector<int> out;
    for(pair<int,int> val: testP){
        int opr = (val.snd + (k%val.fst))%val.fst;
        if(opr == 0){
            out.pb(val.fst);
        }
    }
    
    if(out.size()>0){
        fore(i,0,out.size()){
            cout<<out[i]<<" ";
        }
    }else{
        cout<<"-1";
    }
    cout<<"\n";
}

int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t=1;
    init_sieve();
    init_exp2();
    cin>>t;
    while(t--){
        solve();
    }
}

/*
Notes:

*/