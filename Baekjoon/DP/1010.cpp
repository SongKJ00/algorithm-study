/*
 * https://www.acmicpc.net/problem/1010
 * 다리 놓기 문제
 */

#include <iostream>
#include <vector>
using namespace std;

int dp[30][30];

void initDp()
{
  for(int i = 0; i < 30; i++)
  {
    for(int j = 0; j < 30; j++)
    {
      dp[i][j] = 0;
    }
  }

  for(int i = 1; i < 30; i++)
  {
    dp[1][i] = i;
  }

  for(int i = 2; i < 30; i++)
  {
    for(int j = i; j < 30; j++)
    {
      for(int k = j; k >= i; k--)
      {
        dp[i][j] += dp[i-1][k-1];
      }
    }
  }
}

int main()
{
  vector<long long> answer;
  int T;
  cin >> T;

  initDp();

  for(int caseNum = 0; caseNum < T; caseNum++)
  {
    int N, M;
    cin >> N >> M;
    answer.push_back(dp[N][M]);
  }

  for(auto i: answer)
  {
    cout << i << endl;
  }

  return 0;
}