#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>  //rb_tree
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
typedef __gnu_pbds::priority_queue<int> heap;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
int main() {
  heap h1, h2;
  h1.push(1), h1.push(3);
  h2.push(2), h2.push(4);
  h1.join(h2);
  cout << h1.size() << h2.size() << h1.top() << endl;  // 404
  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> st;
  tree<ll, ll, less<ll>, rb_tree_tag, tree_order_statistics_node_update> mp;
  for (int x : {0, 2, 3, 4}) st.insert(x);
  cout << *st.find_by_order(2) << st.order_of_key(1) << endl;  // 31
  // erase: st.erase(s.find_by_order(s.order_of_key(v)));
}
//__int128_t,__float128_t
