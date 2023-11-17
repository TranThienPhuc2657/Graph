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
const int N=1e5+5;

struct Edge{
    int v;
    ll w;
};
struct Node{
    int u;
    ll du;
};
struct comp{
    bool operator() (Node a, Node b) {
        return a.du>b.du;
    }
};
int n,m,u,v,w;
vll d;
vector <Edge> a[N];
vector <bool> check;

void dijkstra() {
    priority_queue <Node,vector<Node>,comp> h;
    h.push({1,d[1]});
    Edge x;
    while (!h.empty()) {
        u=h.top().u;
        h.pop();
        if (check[u]==true) continue;
        check[u]=true;
        for (auto e:a[u]) {
            int v=e.v;
            ll w=e.w;
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                h.push({v,d[v]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("DIJKSTRA");

    cin >> n >> m;
    REP(i,m) {cin >> u >> v >> w; a[u].pb({v,w});}
    check.resize(n+1,false);
    d.resize(n+1,INF);
    d[1]=0;
    dijkstra();
    if (d[n]==INF) cout << -1;
    else cout << d[n];
    return 0;
}
