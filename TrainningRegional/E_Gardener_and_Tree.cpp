#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for(auto it = l.begin(); it != l.end; it++)
#define fore(i,a,b) for(ll i = a, almo5t = b; i<almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ENDL "\n"
typedef long long int ll;
using namespace std;
/*
   Problem 1:
    We have a small amount of numbers
    Lets determine if we add or substract
    a k*m
    k equal for all of them
    m posibly different for all of them
    we can make them equal

    sol 1:

    Let iterate from -10000 to 10000 with x
    find the differences between each number
    and x
    check if all the differences have a 
    common prime number.
    
    10e4 * 100 * 100

    How 
                
*/

const int MAXN = 20000;

int cr[MAXN]; // -1 if prime, some not trivial divisor if not
vector<int> primes;


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// Function to find gcd of array of
// numbers
int findGCD(vector<int> arr, int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}


void solve(){
    int n;cin>>n;
    int nums[n];fore(i,0,n)cin>>nums[i];
    //Lets check the diferences
    int ans = 0;
    for(int i : nums){
        set<int> diff;
        fore(j,0,n){
            diff.insert(abs(i-nums[j]));
        }

        int k = -1;
        //Check a common prime number for the diffs
        diff.erase(0);
        if(diff.size() == 0){
            ans = -1;
            break;
        }else{
            vector<int> a;
            for(auto x: diff){
                a.pb(x);
            }
            ans = max(ans,findGCD(a,a.size()));
        }
    } 

    cout<<ans<<"\n";
}


int main(){
    FIN;
    //DONT FORGET TO ERASE THIS SHIT XD
    //freopen("../in.txt", "r", stdin);freopen("../out.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        //solve();
        cout<<"a";
    }
}
