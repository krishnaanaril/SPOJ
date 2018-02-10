#include <bits/stdc++.h>

using namespace std;

/* Declare an array to store fibonacci numbers. */
  unsigned long f[201];
  int i;

int init(int n)
{
 
  /* 0th and 1st number of the series are 0 and 1*/
  f[0] = 0;
  f[1] = 1;
 
  for (i = 2; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */
      f[i] = f[i-1] + f[i-2];
  }
 
  return f[n];
}

int main()
{
    init(200);
    cout<<f[90]<<" "<<f[91]<<" "<<f[92]<<" "<<(f[90]+f[91])<<endl;
    return 0;
}
