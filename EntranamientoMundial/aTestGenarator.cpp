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
/*
    Pr1: We have an integer n and k,

    we want to find the kth integer not divisible by n.

    Hint1: Try to look how big are the gaps between multiples
    of n, then try to see how many of this gaps k can cover.

    ----- ----- ----- -----
    k/size of the gaps

    Then to find exactly the number

    k% size of the gaps

    test 1:

    n = 3  k = 7 

    gapzs = 2

    7/2 = 3
    7%2 = 1

    3*3 = 9
    9 +1 = 10

    n = 4 k = 12  

    12 / 3 = 4
    12 % 3 = 0

    4*4 = 16

    if(% == 0) 16-1 

    n = 4 k = 11

    11/3 = 3
    11%3 = 2

    4*3 = 12


    Ob1:

    Q1:

    Sol1:
*/

void solve(){
    int r = rand()%7 +1 ;
    cout<<r<<"\n";
    fore(i,0,r){

        int out = rand()%10000;

        if(rand()%2 == 0){
            out = -out;
        }

        cout<<out<<" ";
    }
    cout<<"\n";
}

int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
