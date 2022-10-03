#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

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

const int MAXN = 3e5;


int main(){
    FIN;
    int t;cin>>t;
    while(t--){
        //Determine where we start.
        ll n,k;cin>>n>>k;

        ll pref[k];fore(i,0,k)cin>>pref[i];
        ll l_diff = -1e10;
        bool can = true;
        
        // fore(i,0,k-1){
        //     if(pref[i]>pref[i+1])can = false;
        //     if(!can)break;
        // }
        
        if(n == k){
            l_diff = pref[0];
        }else{
            if(k>=2){
                l_diff = pref[1]-pref[0];
                if(pref[0]>l_diff*(n-k+1))can = false;
            }
        }
        //cout<<l_diff<<"\n";


        bool cero = false;

        fore(i,0,k-1){
            if(l_diff > pref[i+1] - pref[i])can = false;
            else l_diff = pref[i+1] - pref[i];
            if(!can)break;
        }

        if(can){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
        //cout<<ans<<"\n";
    }

}