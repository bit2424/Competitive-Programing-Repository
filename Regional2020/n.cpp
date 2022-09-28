#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI acos(-1)
#define EPS 1e-9
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


typedef long long ll;
using namespace std;

int sol(string s){
    size_t pos = s.find(".");
    s = s.substr(pos+1);
    //cout<<s<<"\n";
    return stoi(s);
}

int main() {FIN;
    //freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int n; cin>>n;
    int d = 0;
    int ans = 0;
    string s; cin>>s;
    d+= sol(s);
    fore(i,0,n){
        cin>>s;
        d += sol(s);
        d %= 100;
        if(d!=0) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}

