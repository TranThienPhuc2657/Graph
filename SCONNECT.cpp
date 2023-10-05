#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
using ll=long long;
#define file(name) if(fopen(name".INP","r")) {freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}

int n,m,u,v,cnt=0;
int num[N],low[N]; //Danh so va Cung nguoc cao nhat cua diem
stack <int> st; //Cac thanh phan lien thong manh
bool check[N]={false}; //Xet xem da la nhanh cu hay chua
vector <int> a[N];

void dfs(int u) {
    num[u]=low[u]=++cnt;
    st.push(u);
    for (auto v:a[u]) if (!check[v]) {
        if (!num[v]) {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
    if (low[u]==num[u]) {
        int v;
        do {
            v=st.top();
            st.pop();
            check[v]=true;
            cout << v << " ";
        } while (v!=u);
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("SCONNECT");

    cin >> n >> m;
    for (int i=0; i<m; i++) {cin >> u >> v; a[u].push_back(v);}
    for (int i=1; i<=n; i++) if (!num[i]) dfs(i);
    return 0;
}
