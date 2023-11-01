#include <bits/stdc++.h>
using namespace std;
#define file(name) if(fopen(name".inp","r")) {freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define FOR(i,n) for (int i=0; i<n; i++)
#define FORD(i,n) for (int i=n-1; i>=0; i--)
#define pb push_back
#define fi first
#define se second
using ll=long long;
const int N=1e6+5;

int n,k,m,u,v,s,t,previ[N];
bool check[N];
vector <int> a[N];

void bfs(int u) {
    queue <int> q;
    q.push(u);
    check[u]=true;
    previ[u]=1;
    while (!q.empty()) {
        u=q.front();
        q.pop();
        for (auto v:a[u]) if(!check[v]) {
            q.push(v);
            previ[v]=previ[u]+1;
            check[v]=true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("BFS");

    cin >> n >> m; while (m--) {cin >> u >> v; a[u].pb(v);}
    for (int i=1; i<=n; i++) sort(a[i].begin(),a[i].end());
    cin >> s >> t;
    bfs(s);
    cout << previ[t];
    return 0;
}
