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
//const int MAXN = 5;
const int MAXN = 100000;
map<int,int> primes_id;
vector<int> primes;

int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;
}

int main(){
    FIN;
    init_sieve();
    int id = 1;
    fore(i,2,MAXN){
        if(cr[i] == -1){
            primes_id[i] = id;
            primes.pb(i);
            id++;
        }
    }
    //cout<<primes.size()<<"\n";

    int p;cin>>p;

    int n = primes_id[p];
    //cout<<n<<"\n";
    vector<ll> dp(n,0);
    dp[0] = 1;
    fore(i,0,n){
        fore(j,1,n){
            if(i+j<n && primes[i+j]-primes[i]<=14LL){
                dp[i+j] += dp[i]; 
            }else{
                break;
            }
        }
    }
    cout<<dp[n-1];


}