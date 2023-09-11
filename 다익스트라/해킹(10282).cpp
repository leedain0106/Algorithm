// https://www.acmicpc.net/problem/10282
#include <cstdio>
#include <vector>
#include <queue>
#define MAX 1000000000
using namespace std;
vector< pair<int, int> > adj[10001]; // (노드 번호, 가중치) 
int dist[10001];
int visited[10001];

int main(){
  int test_case;
  scanf("%d", &test_case);

  for(int t=0;t<test_case;t++){
    int n, d, c;
    
    scanf("%d %d %d", &n, &d, &c);

    for(int i=0;i<=n;i++){
      visited[i] = 0;
      dist[i] = MAX;
      adj[i].clear();
    }

    for(int i=0;i<d;i++){
      int a, b, s;
      scanf("%d %d %d", &a, &b, &s);
      adj[b].push_back(make_pair(a, s));
    }
    
    priority_queue< pair<int, int> > pq; // (가중치, 노드번호)

    dist[c] = 0;
    pq.push(make_pair(0, c));
    while(!pq.empty()){
      pair<int, int> item = pq.top();
      pq.pop();
      visited[item.second] = 1;
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

    int count = 0;
    int max_v = 0;
    for(int i=1;i<=n;i++){
      if(dist[i] != MAX){
        count++;
        if(dist[i] > max_v) max_v = dist[i];
      }
    }
    printf("%d %d\n", count, max_v);

  }
}