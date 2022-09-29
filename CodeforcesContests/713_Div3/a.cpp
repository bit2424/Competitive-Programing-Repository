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
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
    FIN;
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        string s;cin>>s;
        
        //cout<<a<<" "<<b<<" "<<s<<"\n";
        
        
        int n = s.size();

        fore(i,0,n){
            if(s[i] == '1')b--;
            if(s[i] == '0')a--;
        }

        bool can = true;

        fore(i,0,(n/2)){
            
            int ii = n-i-1;
            
            if(s[i] != s[ii]){
                if(s[i] == '?' || s[ii] == '?'){
                    
                    if(s[i] == '1'){
                        s[ii] = '1';
                        b--;
                    }else if(s[ii] == '1'){
                        s[i] = '1';
                        b--;
                    }else if(s[i] == '0'){
                        s[ii] = '0';
                        a--;
                    }else if(s[ii] == '0'){
                        s[i] = '0';
                        a--;
                    }

                }else{
                    //cout<<i<<" "<<ii<<"\n";
                    can = false;
                }
            }
        }
        
        if(can){
            
            if(n%2){
                int i = (n)/2;
                if(s[i] == '?'){
                    if(a%2){
                        s[i] = '0';
                        a--;
                    }else{
                        s[i] = '1';
                        b--;
                    }
                }
            }

            fore(i,0,(n/2)){
                int ii = n-i-1;
                if(s[i] == '?'){
                    if(a>1){
                        s[i] ='0';
                        s[ii] = '0';
                        a-=2;
                    }else{
                        s[i] = '1';
                        s[ii] = '1';
                        b-=2;
                    }
                }
            }
        } 
        
        if(a!=0 || b!=0) can = false;

        if(can){
            fore(i,0,n){
                cout<<s[i];
            }
        }else{
            cout<<"-1";
        }

        cout<<"\n";
    }

}