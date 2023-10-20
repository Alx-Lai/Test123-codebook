struct TECC {
  // 0-based
  int n, pos = 0;
  vector<int> ord, low, color;
  vector<vector<int>> g, comp;
  TECC(int n) : n(n), ord(n, -1), low(n), color(n, -1), g(n) {}
  void add_edge(int u, int v) {
    g[u].pb(v);
    g[v].pb(u);
  }
  bool is_bridge(int u, int v) {
    if (ord[u] > ord[v]) swap(u, v);
    return ord[u] < low[v];
  }
  void dfs(int u, int p) {
    ord[u] = low[u] = pos++;
    int cnt = 0;
    for (int v : g[u]) {
      if (v == p && cnt == 0) {
        cnt++;
        continue;
      }
      if (ord[v] == -1) dfs(v, u);
      low[u] = min(low[u], low[v]);
    }
  }
  void fill_component(int u) {
    comp.back().pb(u);
    for (int v : g[u]) {
      if (color[v] != -1 || is_bridge(v, u)) continue;
      color[v] = color[u];
      fill_component(v);
    }
  }
  int build() {
    for (int i = 0; i < n; i++) {
      if (ord[i] == -1) dfs(i, i);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (color[i] != -1) continue;
      color[i] = k++;
      comp.pb({});
      fill_component(i);
    }
    return k;
  }
};
// usage:
//  TECC g(n);
//  g.add_edge(a, b);
//  g.build();
//  cout << g.comp[i].size() << ' ';
//  for(int v:g.comp[i]) cout << v << ' ';
