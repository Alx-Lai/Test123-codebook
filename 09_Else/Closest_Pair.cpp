pair<double, double> p[50007], t[50007];
double solve(int l, int r) {
  if (l == r) return INF;
  int mid = (l + r) >> 1;
  double x = p[mid].first;
  double d = min(solve(l, mid), solve(mid + 1, r));
  int i = l, j = mid + 1, id = l;
  while (i <= mid || j <= r) {
    if (i <= mid && (j > r || p[i].second < p[j].second))
      t[id++] = p[i++];
    else
      t[id++] = p[j++];
  }
  for (int i = l; i <= r; i++) p[i] = t[i];
  vector<pair<double, double>> v;
  for (int i = l; i <= r; i++)
    if (abs(p[i].first - x) < d) v.push_back(p[i]);
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (v[j].second - v[i].second >= d) break;
      d = min(d, sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second)));
    }
  }
  return d;
}
main() {
  sort(p + 1, p + n + 1);
  solve(1, n);
}
