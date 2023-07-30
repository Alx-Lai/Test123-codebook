// luogu4779
vector<pii> edge[100020];
int dis[100020];
int vis[100020];
void dijkstra(int s) {
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.emplace(0, s);
  while (pq.size()) {
    int now = pq.top().Y;
    pq.pop();
    if (vis[now])
      continue;
    vis[now] = 1;
    for (pii e : edge[now]) {
      if (!vis[e.X] && dis[e.X] > dis[now] + e.Y) {
        dis[e.X] = dis[now] + e.Y;
        pq.emplace(dis[e.X], e.X);
      }
    }
  }
}
