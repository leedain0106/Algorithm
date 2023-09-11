// https://www.acmicpc.net/problem/1238
#include <cstdio>
#include <vector>
#include <queue>
#define MAX 1000000
using namespace std;
vector< pair<int, int> > adj[1001]; // 노드번호 , 가중치
vector< pair<int, int> > adj_re[1001];
int dist[1001];
int dist_re[1001];
int visited[1001];
int visited_re[1001];
priority_queue< pair<int, int> > pq; // -가중치, 노드번호
int main(){
  int n, m, x;
  scanf("%d %d %d", &n, &m, &x);

  for(int i=0;i<=n;i++){
    dist[i] = MAX;
    dist_re[i] = MAX;
    visited[i] = 0;
    visited_re[i] = 0;
  }

  for(int i=0;i<m;i++){
    int a, b, t;
    scanf("%d %d %d", &a, &b, &t);
    adj[a].push_back(make_pair(b, t));
    adj_re[b].push_back(make_pair(a, t));
  }

  dist[x] = 0;
  visited[x] = 1;
  pq.push(make_pair(0, x));
  while(!pq.empty()){
    pair<int, int> item = pq.top();
    visited[item.second] = 1;
    pq.pop();
    for(int i=0;i<adj[item.second].size();i++){
      int node = adj[item.second][i].first;
      int w = adj[item.second][i].second;
      if(visited[node] == 0){
        if(dist[item.second] + w < dist[node]){
          dist[node] = dist[item.second] + w;
          pq.push(make_pair(-dist[node], node));
        }        
      }
    }
  }

  dist_re[x] = 0;
  visited_re[x] = 1;
  pq.push(make_pair(0, x));
  while(!pq.empty()){
    pair<int, int> item = pq.top();
    visited_re[item.second] = 1;
    pq.pop();
    for(int i=0;i<adj_re[item.second].size();i++){
      int node = adj_re[item.second][i].first;
      int w = adj_re[item.second][i].second;
      if(visited_re[node] == 0){
        if(dist_re[item.second] + w < dist_re[node]){
          dist_re[node] = dist_re[item.second] + w;
          pq.push(make_pair(-dist_re[node], node));
        }        
      }
    }
  }

  int max = 0;
  for(int i=1;i<=n;i++){
    if(dist[i]+dist_re[i] > max) max = dist[i] + dist_re[i];
  }
  
  printf("%d\n", max);
}