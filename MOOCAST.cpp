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
const int N=1005;

struct {
    int x,y;
}pos[N];

struct Edge{
    int u,v;
    ll w;
};

struct comp {
    bool operator() (Edge a, Edge b) {
        return a.w>b.w;
    }
};

int n,u,v;
vll parent;
priority_queue <Edge,vector<Edge>,comp> e;

ll findSet(int u) {
    return parent[u]<0 ?u :parent[u]=findSet(parent[u]);
}

void unionSet(int u, int v) {
    if (parent[u]>parent[v]) swap(u,v);
    parent[u]+=parent[v];
    parent[v]=u;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("MOOCAST");

    cin >> n;
    parent.resize(n+1,-1);
    FOR(i,1,n) cin >> pos[i].x >> pos[i].y;
    FOR(i,1,n-1) FOR(j,i+1,n) e.push({i,j,pow(abs(pos[i].x-pos[j].x),2)+pow(abs(pos[i].y-pos[j].y),2)});
    int cnt=n;
    while (!e.empty()) {
        ll w=e.top().w;
        int s=findSet(e.top().u);
        int r=findSet(e.top().v);
        e.pop();
        if (s!=r) {
            unionSet(s,r);
            if (cnt==2) {cout << w; break;}
            cnt--;
        }
    }
    return 0;
}
