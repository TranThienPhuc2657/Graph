#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}

int n,m,u,v;
bool check[5001]={false};
vector <int> a[5001];
vector <int> res;

void dfs(int u) {
    check[u]=true;
    for (auto v:a[u])
        if (!check[v]) dfs(v);
}

int main() {
    ios_base::sync_with_stdio(0);
    file("COMNET");

    cin >> n >> m;
    for (int i=0; i<m; i++) {cin >> u >> v; a[u].push_back(v); a[v].push_back(u);}
    for (int i=1; i<=n; i++) sort(a[i].begin(),a[i].end());
    int i=2;
    dfs(1);
    while (i<=n) {
        if (!check[i]) {dfs(i); res.push_back(i);}
        i++;
    }
    cout << res.size() << "\n";
    for (int i:res) cout << 1 << " " << i << "\n";
    return 0;
}

