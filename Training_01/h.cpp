#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin, cont.end
#define foreach(it, l) for(auto it = l.begin(); it != l.end; it++)
#define fore(i,a,b) for(ll i = a, almo5t = b; i<almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ENDL "\n"
typedef long long int ll;
using namespace std;

int N = 200;

vector<vector<int>> g(N);
vector<bool> visited(N,0);

int dfs(int a, int go){

}

void solve(){
    int out = 0;
    int limit = 0;
    int top = 6;
    fore(i1,0,top){
        fore(i2,0,top){
            fore(i3,0,top){
                fore(i4,0,top){
                    fore(i5,0,top){
                        fore(i6,0,top){
                            if(i1<=i2 && i2<=i3 && i3<=i4 && i4<= i5 && i5<=i6){
                                cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<i5<<" "<<i6<<" \n";
                                out++;
                                if(i6==4){
                                    limit++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    cout<<out<<" "<<limit<<"\n";
}

int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}

/*
Notes:

*/