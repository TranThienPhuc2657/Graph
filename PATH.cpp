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
const ll INF=LLONG_MAX;
const int N=1000;

int n,m,k,u,v,w,q,d[N][N],trace[N][N];

void tracing(int u, int v) {
    vi path;
    do {
        path.pb(v);
        v=trace[u][v];
    } while (v!=u);
    path.pb(u);
    reverse(path.begin(),path.end());
    cout << path.size() << " ";
    for (auto i:path) cout << i << " ";
    cout << "\n";
}

void Floyd_Warshall() {
    FOR(k,1,n)
        FOR(u,1,n)
            FOR(v,1,n)
                if (d[u][k]!=INT_MAX and d[k][v]!=INT_MAX) //if there is path from u to k and k to v
                    if (d[u][v]>d[u][k]+d[k][v]) {
                        d[u][v]=d[u][k]+d[k][v];
                        trace[u][v]=trace[k][v];
                    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("PATH");

    cin >> n >> m >> k;
    FOR(i,1,n) FOR(j,1,n) if (i!=j) d[i][j]=INT_MAX; else d[i][j]=0;
    REP(i,m) {cin >> u >> v >> w; d[u][v]=w; d[v][u]=w;}
    FOR(u,1,n) FOR(v,1,n) trace[u][v]=u;
    Floyd_Warshall();
    REP(i,k) {
        cin >> q >> u >> v;
        if (q==0) cout << d[u][v] << "\n";
        else tracing(u,v);
    }
    return 0;
}
