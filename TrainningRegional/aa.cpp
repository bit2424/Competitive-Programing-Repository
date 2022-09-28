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

vector<vector<ll>> tree(N, vector<ll>());
vector<bool> visited(N,0L);
vector<ll> p(N,0L);
vector<ll> anc_p(N,0L);
vector<ll> sbt_sum(N,0L);

/*Pr1: We have an array a[], initially empty
And we start adding the mex (smallest non-negative integer not presented in the multiset) 
of a subset of the array, at the end of the array
We have to find the earliest posible error in the process
Or determine that is posible to make that configuration
hint 1: n is really large as well as the a[i]
hint 2: Maybe determine a nice configuration?
hint 3: Given that the array is originally empty,
there is a limited amount of numbers that could occupay
the next position.

Ex:
0 - 0 1
1 - 0 1 2
2 - 0 1 2 3

Sol1: I want to keep the biggest number so far created correctly
that gives me a range of posible number that can come next
check if the next number is in the range, and update the bgn if necessary
*/
void solve(){
    int n;cin>>n;
    int a[n];fore(i,0,n)cin>>a[i];
    int bgn = -1;
    int stp = -1;
    fore(i,0,n){
        if(a[i]<=bgn+1){
            bgn = max(a[i],bgn);
        }else{
            stp = i+1;
            break;
        }
    }
    cout<<stp<<"\n";
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