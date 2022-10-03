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

ll f(vector<ll> t1,vector<ll> t2){
    ll ans = 0;
    int i1 = 0;
    int i2 = 0;
    while(i1<t1.size() && i2<t2.size()){
        if(i1 == i2){
            ans+=t1[i1]*2LL;
            if(i1 == 0)ans-=t1[i1];
            i1++;
        }else{
            ans+=t2[i2]*2LL;i2++;
        }
    }

    if(i1 !=0){
        if(i1 == i2){
            if(i1<t1.size()){ans+=t1[i1]*2LL;i1++;}
        }else{
            if(i2<t2.size()){ans+=t2[i2]*2LL;i2++;}
        }
    }

    while(i1<t1.size())
    {
        ans+=t1[i1];i1++;
    }

    while(i2<t2.size())
    {
        ans+=t2[i2];i2++;
    }
    return ans;
}

int main(){
    FIN;
    int t;cin>>t;
    while(t--){
        //Make two pair arrays
        //Sort them ask for the head to see which one is bigger

        int n;cin>>n;
        ll a[n];fore(i,0,n)cin>>a[i];
        ll b[n];fore(i,0,n)cin>>b[i];
        vector<ll> t1;
        vector<ll> t2;
        fore(i,0,n){
            if(a[i] == 0)t1.pb(b[i]);
            else t2.pb(b[i]);
        }
        ll ans = 0LL;
        sort(ALL(t1));
        sort(ALL(t2));
        reverse(ALL(t2));
        if(t1.size()>=2)reverse(t1.begin()+1,t1.end());
        fore(i,0,t1.size())cout<<t1[i]<<" ";
        cout<<"\n";
        fore(i,0,t2.size())cout<<t2[i]<<" ";
        cout<<"\n";
        ans = max(ans,f(t1,t2));
        if(t1.size()>=2)reverse(t1.begin()+1,t1.end());
        reverse(ALL(t1));
        reverse(ALL(t2));
        if(t2.size()>=2)reverse(t2.begin()+1,t2.end());
        fore(i,0,t1.size())cout<<t1[i]<<" ";
        cout<<"\n";
        fore(i,0,t2.size())cout<<t2[i]<<" ";
        cout<<"\n";
        ans = max(ans,f(t2,t1));

        cout<<ans<<"\n";
    }

}