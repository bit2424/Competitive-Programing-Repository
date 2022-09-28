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
int P = 505;
int K = 55;
int p,k;
vector<vector<int>> lists(P,vector<int>(K,0));
vector<vector<int>> sums(P,vector<int>());

/*

*/
void solve(){
    
}

ll evaluate(ll val){

}

int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    cin>>p>>k;

    fore(i,0,p){
        fore(j,0,k){
            int x;cin>>x;
            lists[i][j] = x;
        }
        sort(lists[i].begin(),lists[i].end());

        int sum = 0;
        fore(j,0,k){
            sum += lists[i][j];
            sums[i].pb(sum);
        }
    }

    /*fore(i,0,k){
        cout<<lists[0][i]<<" ";
    }
    cout<<"\n";
    fore(i,0,k){
        cout<<sums[0][i]<<" ";
    }*/
    
    ll l = 0;
    ll r = 1e9;
    ll result = 501;

    while(l<=r){
        ll r1Val = (double)(r-l)*(1.0/3.0);
        ll r2Val = (double)(r-l)*(2.0/3.0);
        ll r1 = evaluate(r1Val);
        ll r2 = evaluate(r2Val);

        if(r1>r2){
            r = r2;
            l = r1;
        }else{
            r = r1;
            l = r2;
        }
    }
    
}

/*
Notes:

*/  