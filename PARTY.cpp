#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define ll long long
const ll INF=LLONG_MAX;
const int N=1e6+5;

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
int n,m,t,u,v,w;
vector <Edge> a[N];
vector <bool> check;
vector <ll> d;

void dijkstra() { //Dijkstra for node t to all other nodes
    priority_queue <Node,vector <Node>,comp> h;
    h.push({t,d[t]});
    while (!h.empty()) {
        int u=h.top().u;
        h.pop();
        if (check[u]) continue;
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

ll dijkstra2(int i) { //Dijkstra for node i to node t
    priority_queue <Node,vector <Node>, comp> h;
    vector <bool> check2(n+1,false);
    vector <ll> d2(n+1,INF); d2[i]=0;
    h.push({i,d2[i]});
    while (!h.empty()) {
        int u=h.top().u;
        h.pop();
        if (u==t) break;
        if (check2[u]) continue;
        check2[u]=true;
        for (auto e:a[u]) {
            int v=e.v;
            ll w=e.w;
            if (d2[v]>d2[u]+w) {
                d2[v]=d2[u]+w;
                h.push({v,d2[v]});
            }
        }
    }
    return d2[t];
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("PARTY");

    cin >> n >> m >> t;
    d.resize(n+1,INF); d[t]=0;
    check.resize(n+1,false);
    for (int i=0; i<m; i++) {cin >> u >> v >> w; a[u].pb({v,w});}
    dijkstra();
    ll res=-1;
    FOR(i,1,n) res=max(res,dijkstra2(i)+d[i]); //The res is the max(res,the length of i->t + t->i)
    cout << res;
    return 0;
}
