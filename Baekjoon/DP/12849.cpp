#include <iostream>
#include <vector>

using namespace std;

int main()
{
  /*
   * 0: 정보과학관
   * 1: 전산관
   * 2: 미래관
   * 3: 신양관
   * 4: 한경직기념관
   * 5: 진리관
   * 6: 형남공학관
   * 7: 학생회
   */
  vector<long long> dp(8);
  dp[0] = 1;
  long long divisor = 1000000007;
  int D;
  cin >> D;

  for(int i = 0; i < D; i++)
  {
    vector<long long> temp(8);
    temp[0] = (dp[1] + dp[2]) % divisor;
    temp[1] = (dp[0] + dp[2] + dp[3]) % divisor;
    temp[2] = (dp[0] + dp[1] + dp[3] + dp[4]) % divisor;
    temp[3] = (dp[1] + dp[2] + dp[4] + dp[5]) % divisor;
    temp[4] = (dp[2] + dp[3] + dp[5] + dp[6]) % divisor;
    temp[5] = (dp[3] + dp[4] + dp[7]) % divisor;
    temp[6] = (dp[4] + dp[7]) % divisor;
    temp[7] = (dp[5] + dp[6]) % divisor;

    dp = temp;
  }

  cout << dp[0] << endl;
}