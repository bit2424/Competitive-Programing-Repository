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
        //Make two pair arrays
        //Sort them ask for the head to see which one is bigger

        ll n;cin>>n;
        string s;cin>>s;
        vector<int> g(28,-1);
        vector<bool> vis(28,false);
        vector<bool> usd(28,false);

        fore(i,0,n){
            int fnd = s[i]-'a';
            if(!usd[fnd]){
                usd[fnd] = true;
                fore(j,0,26){
                    if(!vis[j]){
                        //check there are no cycles
                        bool can = true;
                        int cnt = 1;
                        g[fnd] = j;
                        int curr = fnd;
                        while(fnd != g[curr] && g[curr]!=-1){
                            curr = g[curr];
                            cnt++;
                        }

                        if(g[curr] != -1 && cnt != 26)can = false;;

                        if(can){
                            vis[j] = true;
                            g[fnd] = j;
                            break;
                        }else{
                            g[fnd] = -1;
                        }
                    }
                }
            }
        }
        
        fore(i,0,n){
            int idx = g[s[i]-'a'];
            char c = idx+'a';
            cout<<c;
        }
        cout<<"\n";
    }

}