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
    vector<int> mp;
    int t;cin>>t;
    while(t--){
        int n,k,r,c;cin>>n>>k>>r>>c;r--;c--;
        vector<vector<char>> mt(n,vector<char>(n,'.'));
        int rr = r%k;
        int cc = c%k;

        fore(i,0,n){
            fore(j,0,n){
                if(((j+rr)%k) == ((i+cc)%k)){
                    mt[i][j] = 'X';
                }
            }
        }

        mt[r][c] = 'X';
        
        fore(i,0,n){
            fore(j,0,n){
                cout<<mt[i][j];
            }
            cout<<"\n";
        }
    }

}