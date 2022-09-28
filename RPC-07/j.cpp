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

vector<vector<int>> v(9, vector<int>(9));
vector<set<int>> r(9),c(9),s(9);

int calcsq(int i, int j){
    if(i < 3 && j < 3) return 0;
    if(i < 3 && j < 6 && j > 2) return 1;
    if(i < 3 && j < 9 && j > 5) return 2;
    if(i > 2 && i < 6 && j < 3) return 3;
    if(i > 2 && i < 6 && j > 2 && j < 6) return 4;
    if(i > 2 && i < 6 && j < 9 && j > 5) return 5;
    if(i > 5 && i < 9 && j < 3) return 6;
    if(i > 5 && i < 9 && j > 2 && j < 6) return 7;
    if(i > 5 && i < 9 && j < 9 && j > 5) return 8;
    return (i/3)*3+j/3;
}

int solvefirst(int i, int j){
    set<int> p = r[i], q = c[j], g = s[calcsq(i,j)];
    set<int> res;
    for(int e: p) res.insert(e);
    for(int e: q) res.insert(e);
    for(int e: g) res.insert(e);
    if(SZ(res) == 8){
        fore(k,1,10){
            if(res.find(k) == res.end()){
                v[i][j] = k;
                r[i].insert(k);
                c[j].insert(k);
                s[calcsq(i,j)].insert(k);
                return 1;
            }
        }
    }
    return 0;
}

set<int> missing(int i, int j){
    set<int> p = r[i], q = c[j], g = s[calcsq(i,j)];
    set<int> res;
    for(int e: p) res.insert(e);
    for(int e: q) res.insert(e);
    for(int e: g) res.insert(e);
    set<int> miss;
    fore(k,1,10){
        if(res.find(k) == res.end()){
            miss.insert(k);
        }
    }
    return miss;
}

int main() {FIN;
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    fore(i,0,9){
        fore(j,0,9){
            cin>>v[i][j];
            if(v[i][j]>0){
                r[i].insert(v[i][j]);
                c[j].insert(v[i][j]);
                s[calcsq(i,j)].insert(v[i][j]);
            }
        }
    }

    int ch = 1;
    while(ch){
        ch = 0;
        fore(i,0,9){
            fore(j,0,9){
                if(v[i][j] == 0){
                    //primera regla
                    if(solvefirst(i,j)){ch=1; continue;}
                    //segunda regla
                    set<int> miss = missing(i,j);
                    //vamo por filas
                    int f = 0;
                    for(int e: miss){
                        int cnt = 0;
                        fore(k,0,9){
                            if(k != j && v[i][k] == 0){
                                set<int> miss2 = missing(i,k);
                                cnt+= (miss2.find(e) != miss2.end());
                            }
                        }
                        if(cnt == 0){
                            //se puede
                            v[i][j] = e;
                            r[i].insert(e);
                            c[j].insert(e);
                            s[calcsq(i,j)].insert(e);
                            ch = 1; f = 1;
                            break;
                        }
                    }
                    if(f) continue;

                    //vamo por col
                    for(int e: miss){
                        int cnt = 0;
                        fore(k,0,9){
                            if(k != i && v[k][j] == 0){
                                set<int> miss2 = missing(k,j);
                                cnt+= (miss2.find(e) != miss2.end());
                            }
                        }
                        if(cnt == 0){
                            //se puede
                            v[i][j] = e;
                            r[i].insert(e);
                            c[j].insert(e);
                            s[calcsq(i,j)].insert(e);
                            ch=1; f = 1;
                            break;
                        }
                    }

                    if(f) continue;

                    //vamo por cuadradito
                    //i = 0 j = 3
                    for(int e: miss){
                        int cnt = 0;
                        int ist = i-(i%3), jst = j-(j%3);

                        fore(k,ist,ist+3){
                            fore(t,jst,jst+3){
                                if(k != i && t != j && v[k][t] == 0){
                                    set<int> miss2 = missing(k,t);
                                    cnt += (miss2.find(e) != miss2.end());
                                }
                            }

                        }
                        if(cnt == 0){
                            //se puede
                            v[i][j] = e;
                            r[i].insert(e);
                            c[j].insert(e);
                            s[calcsq(i,j)].insert(e);
                            ch=1; f = 1;
                            break;
                        }
                    }
                    if(f) continue;
                }
            }
        }

        /*fore(i,0,9){
            fore(j,0,9){
                cout<<v[i][j]<<" ";
            }cout<<"\n";
        }
        exit(0);*/
    }

    int cnt = 0;
    fore(i,0,9) fore(j,0,9) if(v[i][j] == 0) cnt++;
    if(cnt == 0) cout<<"Easy\n";
    else cout<<"Not easy\n";
    fore(i,0,9){
        fore(j,0,9){
            if(v[i][j] == 0) cout<<". ";
            else cout<<v[i][j]<<" ";
        }cout<<"\n";
    }
    return 0;
}

