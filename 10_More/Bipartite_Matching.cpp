// x nodes are numbered 1 to n, y nodes are numbered n+1 to n+m
// g[X].push_back[Y] / g[u].push_back(nx + v)
vector<int> g[200007];
int nx, ny, ma[200007], d[200007];
bool bfs() {
  int i, u, v, len;
  queue<int> Q;
  for (i = 1; i <= nx; i++) {
    if (ma[i] == 0) {
      d[i] = 0;
      Q.push(i);
    } else
      d[i] = INF;
  }
  d[0] = INF;
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    if (u != 0) {
      len = g[u].size();
      for (i = 0; i < len; i++) {
        v = g[u][i];
        if (d[ma[v]] == INF) {
          d[ma[v]] = d[u] + 1;
          Q.push(ma[v]);
        }
      }
    }
  }
  return (d[0] != INF);
}
bool dfs(int u) {
  int i, v, len;
  if (u != 0) {
    len = g[u].size();
    for (i = 0; i < len; i++) {
      v = g[u][i];
      if (d[ma[v]] == d[u] + 1) {
        if (dfs(ma[v])) {
          ma[v] = u;
          ma[u] = v;
          return true;
        }
      }
    }
    d[u] = INF;
    return false;
  }
  return true;
}
int hopcroft_karp() {
  int res = 0, i;
  while (bfs())
    for (i = 1; i <= nx; i++)
      if (ma[i] == 0 && dfs(i))
        res++;
  return res;
}
