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

ll n,k;

bool check(ll l_diff, ll *pref){
    
    bool can = true;

    fore(i,0,k-1){
        if(pref[i]>pref[i+1])can = false;
        if(!can)break;
    }

    fore(i,0,k-1){
        if(l_diff > pref[i+1] - pref[i])can = false;
        else l_diff = pref[i+1] - pref[i];
        if(!can)break;
    }

    return can;
}

int main(){
    FIN;
    int t;cin>>t;
    while(t--){
        //Determine where we start.
        cin>>n>>k;

        ll pref[k];fore(i,0,k)cin>>pref[i];
        
        ll l = -1e10;ll r = 1e10;
        ll start = 0LL;
        while(l<=r){
            ll mid = (l+r)/2;
            //cout<<mid<<'\n';
            if(check(mid,pref)){
                start = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        bool can = true;
        cout<<start<<"\n";
        if(can){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
        //cout<<ans<<"\n";
    }

}