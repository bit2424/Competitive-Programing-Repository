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
typedef long long int ll;
using namespace std;


void solve(){
    string s;cin>>s;
    int n = s.size();
    int sol = 0;
    stack<char> l;
    stack<char> r;
    l.push(s[0]);
    fore(i,1,n){
        r.push(s[i]);
    }

    while(!r.empty()){
        if(l.empty() || l.top() == r.top()){
            l.push(r.top());
            r.pop();
        }else if(l.top() != r.top()){
            l.pop();
            r.pop();
            sol++;
        }
    }

    if(sol%2 == 0){
        cout<<"NET\n";
    }else{
        cout<<"DA\n";
    }
}

int main(){
    FIN;
    freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}

/*
Alice is the odd move
delete adyacent and different in a binary string 
Tell if i can make an equal string in an odd number of moves
100000
100*100
010 -> 0
1010 -> 1

0011
  
0001
 .
    .
*/