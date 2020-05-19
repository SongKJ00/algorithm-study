/*
 * https://www.acmicpc.net/problem/1915
 * 가장 큰 정사각형 문제
 */

#include <iostream>
#include <vector>

using namespace std;

int A[1001][1001];
int dp[1001][1001];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
  {
    string row;
    cin >> row;
    for(int j = 1; j <= m; j++)
    {
      A[i][j] = row[j-1] - '0';
    }
  }

  int result = 0;
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= m; j++)
    {
      if(A[i][j])
      {
        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        result = max(dp[i][j], result);
      }
    }
  }

  cout << result*result << endl;
}