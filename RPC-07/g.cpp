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
    int teams,matches;cin>>teams>>matches;

    int rank[teams];
    fore(i,0,teams){
        rank[i] = i+1;
    }


    fore(m,0,matches){
        string winning; cin>>winning;
        string losing;  cin>>losing;
        int posW = stoi(winning.substr(1))-1;
        int posL = stoi(losing.substr(1))-1;
        //cout<<posW<<" "<<posL<<" \n";
        if(rank[posW]>rank[posL]){
            fore(k,0,teams){
                if(rank[k] < rank[posW] && rank[k] > rank[posL]){
                    rank[k]--;
                }
            }
            rank[posL] = rank[posW];
            rank[posW]--;
        }
        /*fore(i,0,teams){
            cout<<rank[i]<<" ";
        }
        cout<<"\n";*/
    }

    int found = 0;
    int currRank = 1;
    vector<int> ranking;
    while (found<teams)
    {
        fore(i,0,teams){
            if(rank[i] == currRank){
                cout<<"T"<<(i+1);
                if(i+1<=teams){
                    cout<<" ";
                }
                found++;
                currRank++;
                break;
            }
        }
        //cout<<found<<" - ";
    }
    cout<<"\n";
}

int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    //freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}

/*
Notes:

*/