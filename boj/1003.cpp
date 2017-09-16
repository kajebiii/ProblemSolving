#include <stdio.h>
int P0[50] = { 1,0, };
int P1[50] = { 0,1, };
int p0(int n)
{
   if (n > 1)
   {
      if (P0[n]) return P0[n];
      else { P0[n] = p0(n - 1) + p0(n - 2); return P0[n]; }
   }
   else return P0[n];
}
int p1(int n)
{
   if (n > 1)
   {
      if (P1[n]) return P1[n];
      else { P1[n] = p1(n - 1) + p1(n - 2); return P1[n]; }
   }
   else return P1[n];
}

int main()
{
   int x, i, n;
   scanf("%d", &n);
   for (i = 1; i <= n; i++)
   {
      scanf("%d", &x);
      printf("%d %d\n", p0(x), p1(x));
   }
   return 0;
}