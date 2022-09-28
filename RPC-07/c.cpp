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
    int n;cin>>n;
    map<string,int> objects;

    int obj_count = 0;
    fore(i,0,n){
        string name;cin>>name;
        string ob1;cin>>ob1;
        string ob2;cin>>ob2;
        
        if(objects[ob1] == 0){
            obj_count++;
            objects[ob1] = obj_count; 
        }

        if(objects[ob2] == 0){
            obj_count++;
            objects[ob2] = obj_count; 
        }
        //cout<<objects[ob1]<<" "<<objects[ob2]<<"\n";
        g[objects[ob1]].pb(objects[ob2]);
    }

    

    int bestLoop = 0;
    fore(i,1,n+1){
        int pos = i;
        bool win = 0;
        int loop = 0;
        while(!visited[pos]){
            visited[pos] = 1;
            //cout<<pos<<"\n";
            loop+=1;
            if(g[pos].size()>0){
                if(visited[g[pos][0]]){
                    bestLoop = max(bestLoop,loop);
                    break;
                }
                pos = g[pos][0];
            }else{
                break;
            }
        }
        
    }

    if(bestLoop>0){
        cout<<bestLoop;
    }else{
        cout<<"No trades possible";
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