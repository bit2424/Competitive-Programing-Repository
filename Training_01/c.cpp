#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI acos(-1)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

const double eps=1e-9;

double w,h;
int n;

struct pt{
    double x,y;
    pt(double x, double y):x(x),y(y){}
    pt(){}
    double norm2(){return *this**this;}
    double norm(){return sqrt(norm2());}
    pt operator-(pt p){return pt(x-p.x,y-p.y);}
    double operator*(pt p){return x*p.x+y*p.y;}
};

struct circle{
    pt o; double r;
    circle(pt o, double r):o(o),r(r){}
    bool has(pt p){return (o-p).norm()<=r+eps;}
    bool in(circle c){
        double d=(o-c.o).norm();
        return d<=r+c.r+eps;
    }
};

struct UnionFind {
    int n,comp;
    vector<int> uf,si;
    UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1){
        fore(i,0,n)uf[i]=i;}
    int find(int x){return x==uf[x]?x:find(uf[x]);}
    bool join(int x, int y){
        if((x=find(x))==(y=find(y)))return false;
        if(si[x]<si[y])swap(x,y);
        si[x]+=si[y];uf[y]=x;comp--;
        return true;
    }
};

const int MAXN = 1e3+10;
pt p[MAXN];

int main() {FIN;
    cin>>w>>h>>n;
    fore(i,0,n){
        cin>>p[i].x>>p[i].y;
    }
    
    double l = 0, r = 1e14;
    fore(it,0,100){
        double m = (l+r)/2.0;
        UnionFind uf(n+10);
        int can = 1;
        fore(i,0,n){
            circle a(p[i], m);
            fore(j,i+1,n){
                circle b(p[j], m);
                if(a.in(b)){ uf.join(i,j); }
            }
            //up
            if(a.has(pt(p[i].x,h))) uf.join(i,n);
            //down
            if(a.has(pt(p[i].x,0))) uf.join(i,n+1);
            //left
            if(a.has(pt(0,p[i].y))) uf.join(i,n+2);
            //right
            if(a.has(pt(w,p[i].y))) uf.join(i,n+3);
            
            can &= !a.has(pt(w,h)) && !a.has(pt(0,0));
        }
        
        can &= (uf.find(n) != uf.find(n+1));
        can &= (uf.find(n+2) != uf.find(n+3));
        can &= (uf.find(n) != uf.find(n+3));
        can &= (uf.find(n+1) != uf.find(n+2));

        //cout<<fixed<<setprecision(10)<<l<<" "<<r<<" "<<m<<" "<<can<<"\n";

        if(can) l = m;
        else r = m;
    }
    cout<<fixed<<setprecision(10)<<l<<"\n";
    return 0;
}