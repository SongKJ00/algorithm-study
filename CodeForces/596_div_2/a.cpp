#include <iostream>

int main(void)
{
  int da, db;
  int a, b;

  std::cin >> da >> db;

  if(((db - da >= 0) && (db - da <= 1)) || (da == 9 && db == 1))
  {
    if(da == db)
    {
      a = da * 10 + 1;
    }
    else
    {
      a = da * 10 + 9;
    }
    b = a + 1;
    std::cout << a << " " << b << std::endl;
  }
  else
  {
    std::cout << -1 << std::endl;
  }

  return 0;
}