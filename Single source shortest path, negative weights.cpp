#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define ll long long
#define vi vector <int>
#define vll vector <ll>
const ll INF=1e19;
const int N=10000;

struct Edge{
    int v;
    ll w;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("");

    int n,m,q,s;
    cin >> n >> m >> q >> s;
    while (!(n==0 and m==0 and q==0 and s==0)) {
        vector <Edge> e[N];
        vll d(n,INF);
        d[s]=0;
        int u,v;
        ll w;
        REP(i,m) {cin >> u >> v >> w; e[u].pb({v,w});}
        //Bellman-Ford
        REP(i,n-1)
            REP(u,n)
                if (d[u]!=INF)
                    for (auto E:e[u]) d[E.v]=min(d[E.v],d[u]+E.w);
        //Run Bellman-Ford once again to check for negative infinity nodes
        queue <int> negative_infinity;
        REP(u,n)
            if (d[u]!=INF)
                for (auto E:e[u]) {
                    v=E.v;
                    w=E.w;
                    if (d[v]>d[u]+w) negative_infinity.push(v);
                }
        //Run BFS to check for other negative infinity nodes since all children nodes of a -INF node is -INF nodes
        vector <bool> isNeginf(n,false);
        while(!negative_infinity.empty()) {
            u=negative_infinity.front();
            negative_infinity.pop();
            isNeginf[u]=true;
            for (auto E:e[u]) {
                v=E.v;
                if (isNeginf[v]!=true) negative_infinity.push(v);
            }
        }
        //print result
        int t;
        REP(i,q) {
            cin >> t;
            if (d[t]==INF) cout << "Impossible";
            else if (isNeginf[t]) cout << "-Infinity";
            else cout << d[t];
            cout << "\n";
        }
        cout << "\n";
        cin >> n >> m >> q >> s;
    }
    return 0;
}
