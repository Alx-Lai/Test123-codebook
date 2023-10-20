ll modsqrt(ll y, ll p) {
  if (p == 2) return y % p;
  ll x;
  if (qpow(y, (p - 1) / 2, p) == 1) {
    if ((p % 4) == 3)
      x = qpow(y, (p + 1) / 4, p);
    else {
      ll b = 1;
      while (qpow(b, (p - 1) / 2, p) == 1) b++;
      ll i = (p - 1) / 2;
      ll k = 0;
      while (i % 2 == 0) {
        i /= 2;
        k /= 2;
        if ((qpow(y, i, p) * qpow(b, k, p) + 1) % p == 0) k += (p - 1) / 2;
      }
      x = (qpow(y, (i + 1) / 2, p) * qpow(b, k / 2, p)) % p;
    }
    if (2 * x > p) x = p - x;
    return x;
  }
  return -1;
}
