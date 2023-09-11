// https://www.acmicpc.net/problem/18405
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int arr[201][201];
bool cmp(vector<int>& a, vector<int>& b){
  return (a[0] < b[0]) ? true : false;
}
int main(){
  int n,k;
  
  scanf("%d %d", &n, &k);
  queue< pair<int, int> > my_q;
  vector< vector<int> > vec;
  int count = 0;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] != 0){
        vector<int> temp;
        temp.push_back(arr[i][j]);
        temp.push_back(i);
        temp.push_back(j);
        vec.push_back(temp);
        count++;
      }
    }
  }

  int s, x, y;
  scanf("%d %d %d", &s, &x, &y);

  sort(vec.begin(), vec.end(), cmp);

  for(int i=0;i<vec.size();i++){
    my_q.push(make_pair(vec[i][1], vec[i][2]));
  }

  int check = 0;
  int time = 0;
  while(true){
    pair<int, int> item = my_q.front();
    my_q.pop();
    if(item.first-1 > 0 && arr[item.first-1][item.second] == 0){
      arr[item.first-1][item.second] = arr[item.first][item.second];
      my_q.push(make_pair(item.first-1, item.second));
    }
    if(item.second+1 <= n && arr[item.first][item.second+1] == 0){
      arr[item.first][item.second+1] = arr[item.first][item.second];
      my_q.push(make_pair(item.first, item.second+1));
    }
    if(item.first+1 <= n && arr[item.first+1][item.second] == 0){
      arr[item.first+1][item.second] = arr[item.first][item.second];
      my_q.push(make_pair(item.first+1, item.second));
    }
    if(item.second-1 > 0 && arr[item.first][item.second-1] == 0){
      arr[item.first][item.second-1] = arr[item.first][item.second];
      my_q.push(make_pair(item.first, item.second-1));
    }

    check++;
    if(check == count){
      time++;
      count = my_q.size();
      check = 0;
    }
    if(time == s || my_q.empty()){
      break;
    }
  
  }
  printf("%d\n", arr[x][y]);
}