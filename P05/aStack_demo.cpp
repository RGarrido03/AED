//
// Tomás Oliveira e Silva, AED, November 2021
//
// matched-parenthesis verification
//

#include <iostream>
#include "aStack.h"

using std::cout;
using std::cerr;
using std::endl;


int check_parenthesis(const char *s)
{
  aStack<int> stack;
  int j;

  for (j = 0; s[j] != '\0'; j++)
  {
    if (s[j] == '(')
      stack.push(j);
    
    else if (s[j] == ')')
    {
      if (stack.size() > 0)
      {
        cout << "  '(' at position " << stack.top() << " and matching ')' at position " << j << "\n";
        stack.pop();
      }
      else
      {
        cout << "  Unmatched ')' at position " << j << "\n";
        return -1;
      }
    }
  }

  if (stack.is_empty())
    return 0;
  else
    while (!stack.is_empty())
      cout << "  Unmatched '(' at position " << stack.pop() << "\n";
  
  
  return -1;
}

int main(int argc,char **argv)
{
  if(argc == 1)
  {
    cerr << "usage: " << argv[0] << " [arguments...]" << endl;
    cerr << "example: " << argv[0] << " 'abc(def)ghi' 'x)(y'" << endl;
    return 1;
  }
  for(int i = 1;i < argc;i++)
  {
    cout << argv[i] << endl;
    if(check_parenthesis(argv[i]) == 0)
      cout << "  good\n" << endl;
    else
      cout << "  bad\n" << endl;
  }
  return 0;
}
