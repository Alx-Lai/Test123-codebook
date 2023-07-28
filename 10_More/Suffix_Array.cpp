// array c is eventually equal to the position of the suffixes in the suffix
// array don't add another '$' to the string
int sa[400007], c[400007], sa_new[400007], c_new[400007], cnt[400007],
    pos[400007], lcp[400007];
pair<char, int> P[400007];
void calc_suffix_array(string s) {
  s += '$';
  int n = s.size();
  for (int i = 0; i < n; i++)
    P[i] = {s[i], i};
  sort(P, P + n);
  for (int i = 0; i < n; i++)
    sa[i] = P[i].second;
  c[sa[0]] = 0;
  for (int i = 1; i < n; i++)
    c[sa[i]] = c[sa[i - 1]] + (P[i].first > P[i - 1].first ? 1 : 0);
  int k = 1;
  while (k < n) {
    for (int i = 0; i < n; i++)
      sa[i] = (sa[i] - k + n) % n;
    for (int i = 0; i < n; i++)
      cnt[i] = 0;
    for (int i = 0; i < n; i++)
      cnt[c[i]]++;
    pos[0] = cnt[0] - 1;
    for (int i = 1; i < n; i++)
      pos[i] = pos[i - 1] + cnt[i];
    for (int i = n - 1; i >= 0; i--)
      sa_new[pos[c[sa[i]]]--] = sa[i];
    for (int i = 0; i < n; i++)
      sa[i] = sa_new[i];
    c_new[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
      c_new[sa[i]] = c_new[sa[i - 1]];
      pair<int, int> prev = {c[sa[i - 1]], c[(sa[i - 1] + k) % n]};
      pair<int, int> now = {c[sa[i]], c[(sa[i] + k) % n]};
      if (now > prev)
        c_new[sa[i]]++;
    }
    for (int i = 0; i < n; i++)
      c[i] = c_new[i];
    k *= 2;
  }
}
void calc_lcp_array(string s) {
  int n = s.size(), k = 0;
  for (int i = 0; i < n; i++) {
    int j = sa[c[i] - 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k])
      k++;
    lcp[c[i] - 1] = k;
    k = max(k - 1, 0ll);
  }
}
