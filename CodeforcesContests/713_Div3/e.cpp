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



int limit;
int s;
int n;
set<int> ans;

int f(){
    ll sum = 0;
    fore(i,1,limit+2){
        ans.insert(i);
        sum+=i;
    }

    int ii = 0;
    for(int i = limit+1; i>=1; i--){
        
        fore(j,i,n-ii){
            if(sum == s)break;
            sum++;
            ans.erase(j);
            ans.insert(j+1);
        }

        if(sum == s)break;
        ii++;
    }

    return 1;
}

int main(){
    FIN;
    int t;cin>>t;
    while(t--){
        int l,r;
        cin>>n>>l>>r>>s;
        
        limit = r-l;
        
        
        int can = -1;

        if((limit+1)*(limit+2)<=s*2 && 2*s<=(2*n - limit)*(limit+1)){
            can = f();
            //can = 1;
        } 

        
        if(can != 1){
            cout<<-1;
        }else{
            vector<int> n_vis;
            fore(i,1,n+1){
                if(!ans.count(i))n_vis.pb(i);
                //cout<<ans[i]<<" ";
            }
            l--;r--;
            fore(i,0,n){
                if(i>=l && i<=r){
                    cout<<*ans.begin()<<" ";
                    ans.erase(ans.begin());
                }else{
                    cout<<n_vis.back()<<" ";
                    n_vis.pop_back();
                }
            }
        }
        ans.clear();

        cout<<"\n";

    }

}