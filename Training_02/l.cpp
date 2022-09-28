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
    int n,c;cin>>n>>c;
    double area = -1;
    int sides[n];
    fore(i,0,n)cin>>sides[i];

    sort(sides,sides+n);

    double s1 = sides[0];
    double s2 = sides[1];

    fore(i,2,n){
        if(sides[i]<s1+s2){
            double s3 = sides[i];
            double p = (s1+s2+s3)/2;
            area = sqrt(p*(p-s1)*(p-s2)*(p-s3));
        }
    }

    cout<<fixed<<setprecision(9)<<area<<"\n";
}

int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}

/*
Notes:

*/