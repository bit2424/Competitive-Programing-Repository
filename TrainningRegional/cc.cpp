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

int N = 1000005;
ll mod = 998244353;

/*
    Sol1:Se pueden hacer particionamientos de una permutación
    queremos encontrar todos los posibles particionamientos
    que maximicen la siguiente función:
        f(particion) = Es la suma del mayor elemento de cada particion en un particionamiento
    ob1:The ammount of elemments in the permutation is big
    ob2: We should try to find the k biggest elements
    q1: How do we count the ammount of ways we can put these
    elements in different partitions:
    
    sol1: find the k biguest number and then count how many elements
    untill you get to the next k bigguest number
    then you multiply all of those numbers

*/
void solve(){
    int n,k;cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>> pq;

    int p[n];
    fore(i,0,n){
        cin>>p[i];
        if(pq.size()<k){
            pq.push(p[i]);
        }else if( pq.top() <= p[i] ){
            pq.pop();
            pq.push(p[i]);
        }
    }
    /*while(!pq.empty()){
        cout<<pq.top()<<"--\n";
        pq.pop();
    }*/
    int cntk = 0;
    ll ans = 1;
    ll sum = 0;
    fore(i,0,n){
        if(p[i]>=pq.top()){
            cntk++;
            sum = sum + p[i];
            if(cntk==k)break;
            //cout<<sum<<" "<<p[i]<<"\n";
            int cnta = 1;
            while(i+1<n && p[i+1]<pq.top()){
                i++;
                cnta++;
            }
            //cout<<cnta<<"\n";
            ans = (ans*cnta)%mod;
        }
    }

    cout<<sum<<" "<<(ans%mod)<<"\n";
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