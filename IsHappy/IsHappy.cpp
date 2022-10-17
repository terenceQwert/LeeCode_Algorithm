// IsHappy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h> 
#include <iostream>
#include <stdio.h> 


boolean 
Contain(int * nums, int size, int num)
{
  for (int i = 0; i < size; i++)
  {


    if (nums[i] == 0)
      return false;
    if (nums[i] == num)
      return true;
  }
  return false;
}

int next_n(int n)
{
  int r = 0;
  while (n != 0)
  {
    int d = n % 10;
    n /= 10;
    r += d * d;
  }
  return r;
}


// call by value 
// call by address

int main()
{

  int n = 0;
  int history[1000] = { 0 };
  int slot = 0;
  scanf_s("%d", &n);
  while (!Contain(history, 1000, n))
  {
    history[slot] = n;
    slot++;
    n = next_n(n);
    printf("%d\n", n);
    Sleep(1000);
  }
  if (n == 1)
  {
    printf("is happy number \n");
  }
  else
    printf("not happy number \n");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
