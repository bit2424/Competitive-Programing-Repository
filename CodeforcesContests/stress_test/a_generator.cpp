#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a,b) memset(a,b,sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(k, a, b) for (int k = a, almo5t = b; k < almo5t; ++k)
#define SZ(x) ((ll)x.size())
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

const int MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
// Random n numbers between l and r
void num(int l, int r, int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << rand(l,r) << " ";
    }
}
 
//Random n real numbers between l and r with dig decimal places
void real(int l, int r, int dig, int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << rand(l,r) <<"."<<rand(0,pow(10,dig)-1)<< " ";
    }
}
// Random n strings of length l
void str(int l, int n) {
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < l; ++j) {
            int v = rand(1,150);
            if(v%3==0) cout<<(char)rand('a','z');
            else if(v%3==1) cout<<(char)rand('A','Z');
            else cout<<rand(0,9);
        }
        cout<<" ";
    }
}
// Random n strings of max length l
void strmx(int mxlen, int n) {
    for (int i = 0; i < n; ++i)
    {
        int l = rand(1,mxlen);
        for(int j = 0; j < l; ++j) {
            int v = rand(1,150);
            if(3%3==0) cout<<(char)rand('a','z');
            else if(v%3==1) cout<<(char)rand('A','Z');
            else cout<<rand(0,9);
        }
        cout<<" ";
    }
} 
// Random tree of n nodes
void tree(int n) {
    int prufer[n-2];
    for ( int i = 0; i < n; i++ ){
        prufer[i] = rand(1,n);
    }
    int m = n-2;
    int vertices = m + 2; 
    int vertex_set[vertices]; 
    for (int i = 0; i < vertices; i++) 
        vertex_set[i] = 0; 
    for (int i = 0; i < vertices - 2; i++) 
        vertex_set[prufer[i] - 1] += 1; 
    int j = 0; 
    for (int i = 0; i < vertices - 2; i++) { 
        for (j = 0; j < vertices; j++) { 
            if (vertex_set[j] == 0) { 
                vertex_set[j] = -1; 
                cout << (j + 1) << " "
                     << prufer[i] << '\n'; 
                vertex_set[prufer[i] - 1]--; 
                break; 
            } 
        } 
    } 
    j = 0; 
    for (int i = 0; i < vertices; i++) { 
        if (vertex_set[i] == 0 && j == 0) { 
            cout << (i + 1) << " "; 
            j++; 
        } 
        else if (vertex_set[i] == 0 && j == 1) 
            cout << (i + 1) << "\n"; 
    }
}
int main()
{
    int n = 10;
    cout<<"1\n";
    //int mx = 0;
    cout<<n<<" "<<rand(0,n-1)<<"\n";
    fore(i,0,n){
        //mx = max(mx,rand(1,i+1));
        cout<<rand(1,i+1)<<" ";
    }
}