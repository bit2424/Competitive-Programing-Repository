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

vector<set<int>> g(MAXN,set<int>());
vector<int> d(MAXN);
vector<int> p(MAXN);
priority_queue<ii> pq;

void dfs_d(int u,int dd){
    d[u] = dd;
    pq.push({dd,u});
    for(auto w : g[u]){
        dfs_d(w,dd+1);
    }
}

int dfs_upd(int u, int dd, int limit){
    if(dd == limit){
        g[p[u]].erase(u);
        return u;
    }
    return dfs_upd(p[u],dd+1,limit);
}

int main(){
    FIN;
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        fore(i,0,n){
            g[i].clear();
            d[i] = 0;
            p[i] = 0;
        }
        
        pq = priority_queue<ii>();

        fore(i,1,n){
            int a;cin>>a;a--;
            g[a].insert(i);
            p[i] = a; 
        }

        dfs_d(0,0);

        while(k>0){
            ii temp = pq.top();pq.pop();
            int dd = temp.fst;
            int pos_dd = temp.snd;
            if(d[pos_dd] == dd){
                int mid = dd/2;
                if(mid == 0)mid++;
                int cut_pos = dfs_upd(pos_dd,1,mid);
                p[cut_pos] = 0;
                g[0].insert(cut_pos);
                dfs_d(cut_pos,1);
                k--;
            }
        }

        int ans = 1;

        fore(i,0,n){
            ans = max(ans,d[i]);
        }

        cout<<ans<<"\n";
    }

}