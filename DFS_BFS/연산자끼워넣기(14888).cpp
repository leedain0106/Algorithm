// https://www.acmicpc.net/problem/14888
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[11];
int n;
int max_v = -1000000000;
int min_v = 1000000000;
void fun(int pos, int op1, int op2, int op3, int op4, int sum){

  if(pos == n) {
    if (sum > max_v) max_v = sum;
    if (sum < min_v) min_v = sum;
    return;
  }

  if(op1 > 0){
    fun(pos+1, op1-1, op2, op3, op4, sum + arr[pos]);
  }
  if(op2 > 0){
    fun(pos+1, op1, op2-1, op3, op4, sum - arr[pos]);
  }
  if(op3 > 0){
    fun(pos+1, op1, op2, op3-1, op4, sum*arr[pos]);
  }
  if(op4 > 0){
    fun(pos+1, op1, op2, op3, op4-1, sum/arr[pos]);
  }
}
int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }
  int op1, op2, op3, op4;
  scanf("%d", &op1);
  scanf("%d", &op2);
  scanf("%d", &op3);
  scanf("%d", &op4);

  fun(1, op1, op2, op3, op4, arr[0]);
  printf("%d\n%d\n", max_v, min_v);

}