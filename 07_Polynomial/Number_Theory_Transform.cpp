ll r[MAXN], A[MAXN], B[MAXN], C[MAXN];
void ntt(ll x[], ll lim, int opt) {
  for (int i = 0; i < lim; i++) {
    if (r[i] < i) {
      swap(x[i], x[r[i]]);
    }
  }
  int m, k;
  ll gn, g, tmp;
  for (int m = 2; m <= lim; m <<= 1) {
    k = m >> 1;
    gn = qpow(3, (p - 1) / m);
    for (int i = 0; i < lim; i += m) {
      g = 1;
      for (int j = 0; j < k; j++, g = g * gn % p) {
        tmp = x[i + j + k] * g % p;
        x[i + j + k] = (x[i + j] - tmp + p) % p;
        x[i + j] = (x[i + j] + tmp) % p;
      }
    }
  }
  if (opt == -1) {
    reverse(x + 1, x + lim);
    ll inv = qpow(lim, p - 2);
    for (int i = 0; i < lim; i++) x[i] = x[i] * inv % p;
  }
}
void calc() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < m; i++) cin >> B[i];
  while (lim < (n << 1)) lim <<= 1;
  while (lim < (m << 1)) lim <<= 1;
  for (int i = 0; i < lim; i++) r[i] = (i & 1) * (lim >> 1) + (r[i >> 1] >> 1);
  ntt(A, lim, 1);
  ntt(B, lim, 1);
  for (int i = 0; i < lim; i++) C[i] = (A[i] * B[i]) % p;
  ntt(C, lim, -1);
  for (int i = 0; i < n + m - 1; i++) cout << C[i] << ' ';
}