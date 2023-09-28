#include <bits/stdc++.h>
using namespace std;

int n,m,start,ending,previ[100001];
bool check[100001]={false};
vector < int > a[100001];
vector<int> res;

void truy(int u){
     res.push_back(u);
     if (u != start) truy(previ[u]);
     else{
        reverse(res.begin(),res.end());
        cout << res.size() << "\n";
        for (int x:res) cout << x << " ";
     }
}

void dfs(int u) {
    check[u]=true;
    for (auto v:a[u])
        if(!check[v]) {dfs(v); previ[v]=u;}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DFS.INP","r",stdin);
    freopen("DFS.OUT","w",stdout);

    int u,v;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {cin >> u >> v; a[u].push_back(v);}
    for (int i=1; i<=n; i++) sort(a[i].begin(),a[i].end());
    cin >> start >> ending;
    dfs(start);
    truy(ending);
    return 0;
}
