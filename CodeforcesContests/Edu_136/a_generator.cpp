#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a,b) memset(a,b,sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(k, a, b) for (int k = a, almo5t = b; k < almo5t; ++k)
#define SZ(x) ((ll)x.size())
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

const int MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

const int MAXN = 2e5 + 6;


int main(){
    FIN;
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        int aa = a/2;
        if(a%2)aa++;
        int bb = b/2;
        if(b%2)bb++;
        cout<<aa<<" "<<bb<<"\n";
    }

}