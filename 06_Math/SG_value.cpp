int mex(vector<int> &v) {
  int r = 0;
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  while (r < v.size() && v[r] == r) r++;
  return r;
}
int solve() {
  // dp = mex(all(subplate1 ^ subplate2))
  if (dp == 0)
    ;  // Lose
  else
    ;  // Win
}