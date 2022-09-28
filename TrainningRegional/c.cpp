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
    string data;cin>>data;
    vector<pair<char,int>> dcd;
    int  pos = 0;
    fore(i,0,data.size()){
        if(data[i] == '<'){
            pos++;
            if(data[i+1] == '/'){
                dcd.pb({data[i+2],-(pos)});
            }else{
                dcd.pb({data[i+1],pos});
            }
        }
    }

    stack<pair<char,int>> s;

    fore(i,0,dcd.size()){
        if(!s.empty()){
            if(dcd[i].fst == s.top().fst && s.top().snd * dcd[i].snd<0){
                dcd[i].snd = -(s.size());
                dcd[s.top().snd - 1].snd = s.size();     
                s.pop();           
            }else{
                s.push(dcd[i]);
            }
        }else{
            s.push(dcd[i]);
        }
    } 

    //fore(i,0,dcd.size())cout<<dcd[i].fst<<" "<<dcd[i].snd<<"\n";

    fore(i,0,dcd.size()){
        if(dcd[i].snd>=0){
            fore(j,0,2*(dcd[i].snd-1))cout<<" ";
            cout<<"<"<<dcd[i].first<<">";
        }else{
            fore(j,0,-2*(dcd[i].snd+1))cout<<" ";
            cout<<"</"<<dcd[i].first<<">";
        }
        cout<<"\n";
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