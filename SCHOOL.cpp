#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define ll long long
#define vi vector <int>
#define vll vector <ll>
const ll INF=LLONG_MAX;
const int N=5001;

struct Edge{
    int v;
    ll w;
};
struct Node{
    int u;
    ll du;
};
struct comp{
    bool operator() (Node a,Node b) {
        return a.du>b.du;
    }
};
int n,m,k,u,v,w;
vector <Edge> a[N];
vll d;
vi cnt;
vector <bool> check;

void dijkstra() {
    priority_queue <Node,vector<Node>,comp> h;
    h.push({1,0});
    int u;
    while (!h.empty()) {
        u=h.top().u;
        h.pop();
        if (check[u]) continue;
        check[u]=true;
        for (auto e:a[u]) {
            int v=e.v;
            ll w=e.w;
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                h.push({v,d[v]});
                cnt[v]=cnt[u];
            }
            else if (d[v]==d[u]+w) cnt[v]+=cnt[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("SCHOOL");

    cin >> n >> m;
    d.resize(n+1,INF); d[1]=0;
    cnt.resize(n+1,1);
    check.resize(n+1,false);
    REP(i,m) {
        cin >> k >> u >> v >> w;
        a[u].pb({v,w});
        if (k==2) a[v].pb({u,w});
    }
    dijkstra();
    cout << d[n] << " " << cnt[n];
    return 0;
}
