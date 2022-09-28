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

vector<vector<int>> markvisited(int ni,int nj,int si,int sj,vector<vector<int>> visited){
    
    fore(i,si,ni){
        fore(j,sj,nj){
            visited[i][j] = 1;
        }
    }
    return visited;
}

void solve(int n){
    vector<vector<int>> visited(3*n,vector<int>(3*n,0));
    vector<vector<int>> vals(3*n,vector<int>(3*n,-1));
    
    visited = markvisited(n,n,0,0,visited);
    visited = markvisited(3*n,n,2*n,0,visited);
    visited = markvisited(n,3*n,0,2*n,visited);
    visited = markvisited(3*n,3*n,2*n,2*n,visited);


    ll sum = 0;
    
    pair<int,int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    fore(i,0,3*n){
        fore(j,0,3*n){

            if(visited[i][j]) continue;
            queue<pair<int,int>> q;
            q.push({i,j});
            vals[i][j] = 0;
            while(!q.empty()){
                int qi = q.front().fst;
                int qj = q.front().snd;
                q.pop();
                if(visited[qi][qj]) continue;
                fore(d,0,4){
                    int qii = qi+dir[d].fst;
                    int qjj = qj+dir[d].snd;
                    if(qii>=0 && qii<3*n && qjj>=0 && qjj<3*n){

                        if(!visited[qii][qjj] && vals[qii][qjj] == -1){
                            q.push({qii,qjj});
                            vals[qii][qjj] = vals[qi][qj]+1;
                        }
                    }
                }
            }

            //visited[i][j] = 1;
            ll tempSum = 0;
            fore(ii,0,3*n){
                fore(jj,0,3*n){
                    if(vals[ii][jj]>=0){
                        tempSum+=vals[ii][jj];
                    }
                    vals[ii][jj] = -1;
                }
            }

            sum += tempSum;
        }
    }
    
    cout<<(sum/2)<<"\n";

}

int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        int val;cin>>val;
        solve(val);
    }
}

/*
Notes:

*/