#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using ll=long long;
#define file(name) if(fopen(name".INP","r")) {freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define pb push_back

int n,m,u,v,num[N],low[N],cnt=0,bridge=0,cntjoint=0;
vector <int> a[N];
bool joint[N];

void dfs(int u, int pre) {
    num[u]=low[u]=++cnt;
    int child=0;
    for (auto v: a[u]) {
        if (v==pre) continue;
        if (!num[v]) {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]==num[v]) bridge++;
            child++;
            if (u==pre) {if(child>=2) joint[u]=true;}
            else if (low[v]>=num[u]) joint[u]=true;
        } else low[u]=min(low[u],num[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("DFSGRAPH");

    cin >> n >> m;
    while (m--){cin >> u >> v; a[u].pb(v); a[v].pb(u);}
    for (int i=1; i<=n; i++) if (!num[i]) dfs(i,i);
    for (int i=1; i<=n; i++) cntjoint+=joint[i];
    cout << cntjoint << " " << bridge;
    return 0;
}

