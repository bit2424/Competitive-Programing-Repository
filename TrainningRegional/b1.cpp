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


void solve(){
    int n; cin>>n;
    int arr[n];
    fore(i,0,n)cin>>arr[i];
    //fore(i,0,n)cout<<arr[i]<<" ";
    //cout<<" -- \n";
    //sort(arr,arr+n);
    int sol = 0;
    fore(i,0,n){
        double ai = arr[i];
        double posi = i+1;
        //cout<<posi<<"/"<<ai<<"\n";
        if(ai>posi){

            double dif =  ai-posi;

            for(double posj = dif; posj<=n ; posj+=ai){
                if(posj<=posi)continue;
                double aj = arr[((int)posj) - 1];
                if(EPS> abs(aj - ((posi+posj)/ai))){
                    //cout<<posj<<" - "<<aj<<" ";
                    sol++;
                }
            }

        }else if(posi>ai){
            
            double dif = ai - ((int)posi%(int)ai);

            for(double posj = dif+ai; posj<=n ; posj+=ai){
                if(posj<=posi)continue;
                double aj = arr[((int)posj) - 1];
                
                if(EPS> abs(aj - ((posi+posj)/ai)) ){
                    //cout<<posj<<" - "<<aj<<" ";
                    sol++;
                }
            }

        }else{
            double dif = posi-ai;

            for(double posj = ai; posj<=n ; posj+=ai){
                if(posj<=posi)continue;
                double aj = arr[((int)posj) - 1];
                if(EPS> abs(aj - ((posi+posj)/ai)) ){      
                    //cout<<posj<<" - "<<aj<<" ";
                    sol++;
                }
            }

        }
        //cout<<"\n";
    }
    
    cout<<sol<<"\n";
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

/*
Notes:

*/