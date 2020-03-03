/*
 * https://www.acmicpc.net/problem/2231
 * 분해합 문제
 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int result = 0;
  int N;
  cin >> N;

  for(int i = 1; i < N; i++)
  {
    string str = to_string(i);
    int restSum = 0;
    for(int j = 0; j < str.size(); j++)
    {
      restSum += str[j] - '0';
    }
    if(i + restSum == N)
    {
      result = i;
      break;
    }
  }

  cout << result << endl;

  return 0;
}