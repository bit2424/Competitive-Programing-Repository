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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int b[n];
        int a[n+1];
        fore(i,0,n){
            cin>>b[i];
        }
        a[0] = b[0];
        bool can = true;
        fore(i,1,n){
            int op1 = a[i-1]+b[i];
            int op2 = a[i-1]-b[i];
            //cout<<op1<<" "<<op2<<"\n";
            if(op1>=0 && op2>=0 && op1 != op2){
                can = false;
                break;
            }else if(op1>=0){
                a[i] = op1;
            }else if(op2>=0){
                a[i] = op2;
            }else{
                can = false;
                break;
            }
        }

        if(can){
            fore(i,0,n){
                cout<<a[i]<<" ";
            }
        }else{
            cout<<"-1";;
        }
        cout<<"\n";
    }

}