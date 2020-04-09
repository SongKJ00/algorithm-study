/*
 * 124 나라의 숫자
 * https://programmers.co.kr/learn/courses/30/lessons/12899
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
  string answer = "";
  char ch[] = {'4', '1', '2'};
  while(n > 0)
  {
    int ret = n % 3;
    n /= 3;
    if(ret == 0)
    {
      n--;
    }
    answer = ch[ret] + answer;
  }
  return answer;
}

int main() {
  std::cout << solution(6) << std::endl;
}