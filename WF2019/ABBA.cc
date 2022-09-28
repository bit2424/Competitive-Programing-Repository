
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
    
#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a,b) memset(a,b,sizeof(a));
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

    
const long double EPS = 1e-9;


/*
    Petrozavodsk  Winter  Training  Camp  2016 A
    Pr1:
    We define a multiplication table,
    with 2 a,b vectors of real numbers of size h and w
    then in the ith row and jth colum we have 
    a[i]*b[i]

    we have an empty table but we can add tables generated
    as before such that we get a desire table

    los valores en los vectores pueden ser reales
    Pero los de la tabla son enteros.

    hint1: h and w are small
    

*/
    
long double reduce(vector<vector<long double> >& x){ // returns determinant
    int n=x.size(),m=x[0].size();
    int i=0,j=0;long double r=1.;
    while(i<n&&j<m){
        int l=i;
        fore(k,i+1,n)if(abs(x[k][j])>abs(x[l][j]))l=k;
        if(abs(x[l][j])<EPS){j++;r=0.;continue;}
        if(l!=i){r=-r;swap(x[i],x[l]);}
        r*=x[i][j];
        for(int k=m-1;k>=j;k--)x[i][k]/=x[i][j];
        fore(k,0,n){
            if(k==i)continue;
            for(int l=m-1;l>=j;l--)x[k][l]-=x[k][j]*x[i][l];
        }
        i++;j++;
    }
    return r;
}
    
int main()
{
    FIN;
#ifdef LOCAL
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#else
#define endl '\n'
#endif
    
    
    
    int h,w;cin>>h>>w;
    vector<vector<long double> > a(h,vector<long double>(w));
    fore(i,0,h){
        fore(j,0,w){
            cin >> a[i][j];
        }
    }
    reduce(a);
    ll rrank = 0;
    fore(i,0,h){
        fore(j,0,w){
            if(a[i][j] != 0) {
                rrank++;break;
            }
        }
    }

    vector<vector<long double> > b(w,vector<long double>(h));

    fore(i,0,h){
        fore(j,0,w){
            b[j][i] = a[i][j];
        }
    }
    reduce(b);

    ll crank = 0;
    fore(j,0,w){
        fore(i,0,h){
            if(b[i][j] != 0) {
                crank++;break;
            }
        }
    }
    cout<<min(rrank,crank)<<endl;
    return 0;
}
