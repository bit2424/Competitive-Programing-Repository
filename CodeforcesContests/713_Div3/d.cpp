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
    // freopen("../../in.txt", "r", stdin);
    // freopen("../../out.txt", "w", stdout);
    
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        n+=2;
        ll sum = 0LL;
        ll a[n];
        fore(i,0,n){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a,a+n);
        bool can = false;

        if(n>=3){
            if(sum-a[n-1]-a[n-2] == a[n-2]){
                can = true;
                fore(i,0,n-2){
                    cout<<a[i]<<" ";
                }
            }else{
                int j = -1;
                fore(i,0,n-1){
                    if(sum-a[i]-a[n-1] == a[n-1]){
                        j = i;
                        can = true;
                        break;
                    }
                }
                
                if(can){
                    fore(i,0,n-1){
                        if(i!=j){
                            cout<<a[i]<<" ";
                        }
                    }
                    
                }
            }
        }
        
        if(!can){
            cout<<-1;
        }

        cout<<"\n";

    }

}