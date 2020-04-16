/*
 * https://www.acmicpc.net/problem/9465
 * 스티커 문제
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int T;
  vector<int> answer;
  cin >> T;
  for(int caseNum = 0; caseNum < T; caseNum++)
  {
    int n;
    cin >> n;
    vector<vector<int>> dp(2);
    dp[0].resize(n+2);
    dp[1].resize(n+2);
    for(int i = 0; i < 2; i++)
    {
      for(int j = 2; j < n+2; j++)
      {
        cin >> dp[i][j];
      }
    }

    for(int i = 2; i < n+2; i++)
    {
      dp[0][i] += max(dp[1][i-1], dp[1][i-2]);
      dp[1][i] += max(dp[0][i-1], dp[0][i-2]);
    }
    answer.push_back(max(dp[0][n+1], dp[1][n+1]));
  }

  for(auto i: answer)
  {
    cout << i << endl;
  }

  return 0;
}