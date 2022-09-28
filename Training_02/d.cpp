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


void solve(){
    string s;cin>>s;
    int k;cin>>k;
    //necesito un vector pa saber las pocisiones fijas
    vector<int> fxPos;
    //Otro vector para saber si en está posición es espcial
    vector<pair<char,int>> msg;
    int fx = 0;
    
    for(int i = s.size()-1; i>=0; i--){
        char lst = s[i];
        if(lst == '*'){
            msg.pb({s[i-1],-2});
            i--;
        }else if(lst == '?'){
            msg.pb({s[i-1],-1});
            i--;
        }else{
            msg.pb({s[i],0});
            fx++;
        }
    }
    fxPos.pb(fx);
    fore(i,0,msg.size()){
        if(msg[i].snd<0){
            fxPos.pb(fxPos.back());
        }else{
            fxPos.pb(fxPos.back()-1);
        }
    }

    fxPos.erase(fxPos.begin());
    //reverse(fxPos.begin(),fxPos.end());
    int count = 0;
    fore(i,0,fxPos.size()){
        //cout<<<<" ";
        if(msg[i].snd<0){
            if(count+fxPos[i]<=k){
                int put = k - (count+fxPos[i]);
                if(msg[i].snd == -1) msg[i].snd = min(1,put);
                if(msg[i].snd == -2) msg[i].snd = put;
                count += msg[i].snd;
            }
        }else{
            count++;
            msg[i].snd = 1;
        }
        //cout<<msg[i].fst<<","<<msg[i].snd<<" "<<fxPos[i]<<" "<<count<<"\n";
    }
    //cout<<"\n";
    if(count==k){
        for(int i = msg.size()-1; i>=0; i--){
            fore(j,0,msg[i].snd){
                cout<<msg[i].fst;
            }
        }
        cout<<"\n";
    }else{
        cout<<"Impossible\n";
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