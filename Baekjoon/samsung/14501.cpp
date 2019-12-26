#include <iostream>

int T[16];
int P[16];
int dp[17] = {0, };

int main()
{
  int N;

  std::cin >> N;
  for(int i = 1; i <= N; i++)
  {
    std::cin >> T[i] >> P[i];
  }

  for(int day = N; day >= 1; day--)
  {
    if((day + (T[day]-1)) <= N)
    {
      int ret = P[day] + dp[day + T[day]];
      dp[day] = std::max(ret, dp[day+1]);
    }
    else
    {
      dp[day] = dp[day+1];
    }
  }

  std::cout << dp[1] << std::endl;
  return 0;
}