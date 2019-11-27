#include <iostream>
#include <math.h>

int main(void)
{
  int n, p;
  std::cin >> n >> p;

  if(n <= p)
  {
    std::cout << -1 << std::endl;
  }
  else
  {
    int cnt = 0;
    int tempP = -1 * p;
    for(;;)
    {
      n += tempP;
      cnt++;
      if(n < 0)
      {
        std::cout << -1 << std::endl;
        break;
      }
      else
      {
        unsigned int tempN = n;
        int setBitCnt = 0;
        int lastSetBitPos = -1;
        while(tempN)
        {
          setBitCnt += tempN & 1;
          tempN >>= 1;
          lastSetBitPos++;
        }
        if(cnt >= setBitCnt)
        {
          if(cnt > pow(2, lastSetBitPos))
          {
            std::cout << -1 << std::endl;
          }
          else
          {
            std::cout << cnt << std::endl;
          }
          break;
        }
      }
    }
  }

  return 0;
}
