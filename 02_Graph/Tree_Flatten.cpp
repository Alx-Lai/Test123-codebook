int timer = 0;
int st[MAXN], ed[MAXN];
void flat(int id, int pa) {
  st[id] = ++timer;
  for (int v : fltree[id]) {
    if (v == pa) continue;
    flat(v, id);
  }
  ed[id] = timer;
  // cerr << id << "--" << st[id] << ", " << ed[id] << '\n';
}
