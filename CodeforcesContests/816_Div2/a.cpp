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

        ll p1 = 1;
        ll p2 = 3;
        ll p3 = p2+(n/3);

        //cout<<p1<<" "<<p2<<" "<<p3<<"\n";

        ll l[3] = {0,0,0};
        l[0] = p2-p1;
        l[1] = p3-p2;
        l[2] = (n+1)-p3;
        ll range = 1e9;
        fore(i,0,3){
            range = min(range,abs(l[i]-l[(i+1)%3]));
        }
        cout<<range<<"\n";
    }

}