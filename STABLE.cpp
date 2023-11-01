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

int n,m,u,v,s,previ[N];
bool check[N];
set <int> st,a[N]; //set a[N] do no la da do thi

void bfs(int u) {
    queue <int> q;
    q.push(u);
    check[u]=true;
    while (!q.empty()) {
        u=q.front();
        q.pop();
        for (auto v:a[u])
            if(!check[v]) {q.push(v); check[v]=true; previ[v]=previ[u]+1;}
            else if (previ[u]+1==previ[v]) {st.insert(v); q.push(v);}
            //Viec q.push(v) cho du v da check nhu the nay la vi de cho cac dinh noi voi v cung
            //se la mang on dinh, neu khong lam vay thi v chi xet 1 lan va no se khong coi nhu la
            //mot mang on dinh
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("STABLE");

    cin >> n >> m >> s;
    while(m--) {cin >> u >> v; a[u].insert(v);}
    bfs(s);
    cout << st.size();
    return 0;
}
