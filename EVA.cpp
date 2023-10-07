#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
using ll=long long;
#define file(name) if(fopen(name".INP","r")) {freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define pb push_back

int n,k,m,u,v,res[N];
vector <int> a[N],escape;

void bfs(int u) {
    int previ[N]={0};
    bool check[N]={false};
    queue <int> q;
    q.push(u);
    check[u]=true;
    res[u]=0;
    while (!q.empty()) {
        for (auto v:a[u]) if(!check[v]) {
            q.push(v);
            previ[v]=previ[u]+1;
            res[v]=min(res[v],previ[v]);
            check[v]=true;
        }
        q.pop();
        u=q.front();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("EVA");

    int temp;
    cin >> n >> k; while (k--) {cin >> temp; escape.pb(temp);}
    memset(res,0x3f,sizeof(res));
    cin >> m; while (m--) {cin >> u >> v; a[u].pb(v); a[v].pb(u);}
    for (auto i:escape) bfs(i);
    for (int i=1; i<=n; i++) cout << res[i] << " ";
    return 0;
}
