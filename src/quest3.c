#include <stdio.h>
int fibonacci(int N)  
{
  if (N == 1 || N == 2)
    return 1; 
  return fibonacci(N - 1) + fibonacci(N - 2); 
}
int main()
{
  int N;
  int x;
  scanf("%d", &N); 
  for (int i = 1; i <= N; i++) 
    x = fibonacci(i);
  printf("%d", x);  
  getchar();
  return 0;
}