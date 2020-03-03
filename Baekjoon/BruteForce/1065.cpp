/*
 * https://www.acmicpc.net/problem/1065
 * 한수 문제
 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int answer = 0;
  int N;
  cin >> N;

  for(int i = 1; i <= N; i++)
  {
    bool flag = true;
    int gap = 0;
    string str = to_string(i);
    for(int j = 0; j < str.size()-1; j++)
    {
      int curr = str[j] - '0';
      int next = str[j+1] - '0';
      if(j == 0)
      {
        gap = curr - next;
      }
      if(curr - next != gap)
      {
        flag = false;
        break;
      }
    }
    if(flag)
    {
      answer++;
    }
  }

  cout << answer << endl;
}