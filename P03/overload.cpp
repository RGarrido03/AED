//
// Tomás Oliveira e Silva, AED, October 2021
//
// example of function overloading (same function name, different argument numbers and/or data types)
//

#include <iostream>

using std::cout; // make this symbol from the std namespace directly visible

void show(const int i)
{
  cout << "int: "
       << i
       << std::endl;
}

void show(const double d)
{
  cout << "double: "
       << d
       << std::endl;
}

void show(const char *s,const char *h = "string: ") // second argument with default value
{
  cout << h
       << s
       << std::endl;
}

void show(const char s)
{
  cout << "char: "
       << s
       << std::endl;
}

void show(int *i, const int size=3)
{
  cout << "array: [";
  for (int a = 0; a < size-1; a++)
  {
    cout << i[a]
         << ", ";
  }
  cout << i[size-1]
       << "]"
       << std::endl;
}

int main(void)
{
  show(1.0);
  show("hello");
  show(-3);
  show("John","name: ");
  show('a');
  int i[3] = {2,7,-1};
  show(i,3);
  return 0;
}
