// https://www.acmicpc.net/problem/11779
#include <cstdio>
#include <vector>
#include <queue>
#define ll long long
#define MAX 10000000000
using namespace std;
vector< pair<int, int> > adj[1001];
ll dist[1001];
int before[1001];
int visited[1001];
priority_queue< pair<ll, int> > pq; // -가중치, 노드번호
int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  // 초기화
  for(int i=0;i<=n;i++){
    dist[i] = MAX;
    visited[i] = 0;
    before[i] = -1;
  }

  for(int i=0;i<m;i++){
    int a, b, s;
    scanf("%d %d %d", &a, &b, &s);
    adj[a].push_back(make_pair(b, s));
  }

  int s, e;
  scanf("%d %d", &s, &e);

  dist[s] = 0;
  pq.push(make_pair(0, s));
  int check = 0;
  while(!pq.empty()){
    pair<ll, int> current = pq.top();
    if(visited[current.second] == 1){
      pq.pop();
      continue;
    }
    check++;
    if(check == n) break;
    visited[current.second] = 1;
    pq.pop();
    for(int i=0;i<adj[current.second].size();i++){
      int node = adj[current.second][i].first;
      int w = adj[current.second][i].second;
      if(visited[node] == 0){
        if(dist[current.second] + w < dist[node]){
          dist[node] = dist[current.second] + w;
          pq.push(make_pair(-dist[node], node));
          before[node] = current.second;
        }
      }
    }
  }

  printf("%lld\n", dist[e]);
  vector<int> result;
  int count = 0;
  while(e != -1){
    count++;
    result.push_back(e);
    e = before[e];
  }

  printf("%d\n", count);
  for(int i=result.size()-1;i>=0;i--){
    printf("%d ", result[i]);
  }
  printf("\n"); 
}