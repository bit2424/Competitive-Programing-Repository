#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;

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

vector<vector<int>> g(MAXN,vector<int>());
vector<int> d(MAXN);

int n,k;
int cnt;
int mid;

int check(int u, int pr, int limit){
    int dpth = 0;
    for(auto v : g[u]){
        dpth = max(dpth,check(v,u,limit+1));
    }
    dpth++;
    if(dpth == mid && pr != 0 && u != 0){
        cnt++;
        return 0;
    }
    return dpth;
}

int main(){
    FIN;
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        fore(i,0,n){
            g[i].clear();
        }
        
        fore(i,1,n){
            int a;cin>>a;a--;
            g[a].pb(i);
        }

        int l = 1;
        int r = 3e5;
        int ans = 1;

        while(l<=r){
            mid = (l+r)/2;
            cnt = 0;
            check(0,0,0);
            if(cnt<=k){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }


        cout<<ans<<"\n";
    }

}