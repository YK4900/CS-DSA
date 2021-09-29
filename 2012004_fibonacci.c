#include <stdio.h>
#define Limit 4500
char arr1[Limit];
char arr2[Limit];
char result[Limit];

void sum(char arr1[], char arr2[], char result[])
{
  int carry = 0;
  for (int i = Limit - 1; i >= 0; i--)
  {
    int digit = (arr1[i] - '0') + (arr2[i] - '0') + carry;
    result[i] = (digit % 10) + '0';
    carry = digit / 10;
  }
}

void copy(char arr1[], char arr2[])
{
  for (int i = Limit - 1; i >= 0; i--)
    arr1[i] = arr2[i];
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < Limit; i++)
  {
    arr1[i] = '0';
    arr2[i] = '0';
    result[i] = '0';
  }
  arr2[Limit - 1] = '1';
  
  if (n == 0 || n == 1)
  {
    printf("%c", n + '0');
  }
  else
  {
    for (int i = 2; i <= n; i++)
    {
      sum(arr1, arr2, result);
      copy(arr1, arr2);
      copy(arr2, result);
    }

    int begin = 0;
    for (int i = 0; i < Limit; i++)
    {
      if (begin == 0 && result[i] == '0')
        continue;

      if (begin == 0 && result[i] != '0')
        begin = 1;
      printf("%c", result[i]);
    }
    printf("\n");
  }
  return 0;
}
