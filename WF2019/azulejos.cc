#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for(auto it = l.begin(); it != l.end; it++)
#define fore(i,a,b) for(ll i = a, almo5t = b; i<almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ENDL "\n"
typedef long long int ll;
using namespace std;

int N = 1000005;

struct az{
    int i;
    ll h;
    ll p;
};

bool cmp_min(const az &a, const az &b){
    if(a.p != b.p) return a.p<b.p;
    return a.h<b.h;
}

bool cmp_max(const az &a, const az &b){
    if(a.p != b.p) return a.p<b.p;
    return a.h>b.h;
}
/*

*/
void solve(){
    int n;cin>>n;
    vector<az> back(n);
    vector<az> front(n);
    fore(i,0,n){
        cin>>back[i].p;
        back[i].i=i+1;
        front[i].i=i+1;
    }
    fore(i,0,n){
        cin>>back[i].h;
    }
    fore(i,0,n){
        cin>>front[i].p;
    }
    fore(i,0,n){
        cin>>front[i].h;
    }
    sort(all(back),cmp_min);
    sort(all(front),cmp_max);

    vector<int> back_prices;
    vector<int> front_prices;
    int last_p = -1;
    fore(i, 0, n){
        if (back[i].p == last_p){
            continue;
        }else{
            back_prices.push_back(i);
            last_p = back[i].p;
        }
    }

    last_p = -1;
    fore(i, 0, n){
        if (front[i].p == last_p){
            continue;
        }else{
            front_prices.push_back(i);
            last_p = front[i].p;
        }        
    }

    int current  = 0;
    
    while (current < n)
    {
        
    }
    

    fore(i,0,n){
        cout<<"back "<<back[i].i<<" p "<<back[i].p<<" h "<<back[i].h<<endl;
    }
    fore(i,0,n){
        cout<<"front "<<front[i].i<<" p "<<front[i].p<<" h "<<front[i].h<<endl;
    }
    fore(i,0,n){
        if(back[i].h<=front[i].h){
            cout<<"Impossible "<<i<<back[i].h<<front[i].h<<endl;
        }
    }
    fore(i,0,n){
        cout<<back[i].i<<' ';
    }
        cout<<endl;
       fore(i,0,n){
        cout<<front[i].i<<' ';
    } 
}

int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}

/*
Notes:

*/  