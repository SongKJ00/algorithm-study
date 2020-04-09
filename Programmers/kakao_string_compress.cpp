/*
 * 문자열 압축
 * https://programmers.co.kr/learn/courses/30/lessons/60057
 * [2020카카오공채]
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
  int answer = s.length();

  if(answer == 1) { return 1; }

  for(int i = 1; i <= s.length()/2; i++)
  {
    string unit = s.substr(0, i);
    string cp, comp;
    int cnt = 1;
    for(int j = i; j < s.length(); j+=i)
    {
      comp = s.substr(j, i);
      if(unit.compare(comp) == 0)
      {
        cnt++;
      }
      else
      {
        if(cnt == 1)
        {
          cp += unit;
        }
        else
        {
          cp += to_string(cnt) + unit;
          cnt = 1;
        }
        unit = comp;
      }

      if(j+i >= s.length())
      {
        if(cnt != 1)
        {
          cp += to_string(cnt) + unit;
        }
        else
        {
          cp += s.substr(j);
        }
        break;
      }
    }

    answer = answer > cp.length() ? cp.length() : answer;
  }

  return answer;
}

int main()
{
  std::cout << solution("xababcdcdababcdcd") << std::endl;
}