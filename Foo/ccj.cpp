#include <iostream>
#include <vector>

int main()
{
  int case1ret = 0;
  int case2ret = 0;

  std::string str;
  std::cin >> str;

  for(int i = 0; i < str.size() - 1; i++)
  {
    if(str[i] == str[i+1])
    {
      case1ret++;
    }
  }

  int cnt = 0;
  char ch = str[0];
  std::vector<int> chConts;

  for(int i = 0; i < str.size() - 1; i++)
  {
    if(str[i] == str[i+1])
    {
      cnt++;
    }
    else
    {
      if(cnt != 0)
      {
        chConts.push_back(cnt+1);
        cnt = 0;
      }
    }
  }
  if(cnt != 0)
  {
    chConts.push_back(cnt+1);
  }

  for(int i = 0; i < chConts.size(); i++)
  {
    case2ret += chConts[i] / 2;
  }
  std::cout << case1ret << " " << case2ret << std::endl;
}