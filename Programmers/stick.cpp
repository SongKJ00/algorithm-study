/*
 * 쇠막대기
 * https://programmers.co.kr/learn/courses/30/lessons/42585
 */
#include <string>
#include <vector>
#include <iostream>


using namespace std;

int solution(string arrangement) {
  int answer = 0;
  int cnt = 0;
  for(int i = 0; i < arrangement.size()-1; i++)
  {
    if(arrangement[i] == '(' && arrangement[i+1] == ')')
    {
      answer += cnt;
      i++;
    }
    else if(arrangement[i] == '(')
    {
      cnt++;
    }
    else if(arrangement[i] == ')')
    {
      answer++;
      cnt--;
    }
  }
  int size = arrangement.size();
  if(size >= 2)
  {
    if(arrangement[size-2] != '(' && arrangement[size-1] == ')')
    {
      answer++;
    }
  }
  return answer;
}

int main()
{
  std::cout << solution("()(((()())(())()))(())") << std::endl;
}