#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> arr(n+1);
  vector<vector<int>> dp(n+1);
  for(int i = 0; i <= n; i++)
  {
    arr[i].resize(n+1);
    dp[i].resize(n+1);
  }

  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= i; j++)
    {
      cin >> arr[i][j];
    }
  }

  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= i; j++)
    {
      dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
    }
  }

  int result = 0;
  for(int j = 1; j <= n; j++)
  {
    result = max(result, dp[n][j]);
  }

  cout << result << endl;

}
