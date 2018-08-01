//
//所谓表达式求值，就是写一个微型计算器。例如输入：（1+9）* 2 / 2 - 1，输出9。
//对于这样的问题，我们一般利用栈，模拟数学运算来完成。
//为了简化问题，在继续下面的分析之前，先在此作个约定：本文只讨论+-*/()基本的四则运算，
//另外不对意外出现的符号（例如^）和不符合规范的数学表达式（例如2*-1）做异常处理。
//
//

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

typedef struct oprator
{

  string op = "+-*/()#";
  int find_loca() 
  {

  }

  int relation[7][7] = 
  {
    {1,  1,  -1,  -1,  -1,  1,  1},
    {1,  1,  -1,  -1,  -1,  1,  1},
    {1,  1,  1,   1,   -1,  1,  1},
    {1,  1,  1,   1,   -1,  1,  1},
    {-1, -1, -1,  -1,  -1,  0,  -2},
    {1,  1,  1,   1,   -2,  1,  1},
    {-1, -1, -1,  -1,  -1,  -2, 0}
  };

}oprator;

// 判断字符类型
// 0，数字；1，符号；-1，非法
int chartype(char c)
{
  if( '0' <= c && c <= '9') return 0;
  if( c == '+'
      || c == '-'
      || c == '*' 
      || c == '/'
      || c == '('
      || c == ')'
      || c == '#'
    ) return 1;
  return -1;
}; 

// 比较两个操作符的优先级
int com(char op1,char op2)
{
  // jinhaiqitodo
  return 0;
};

// 计算
int calc(char op,int num1,int num2)
{
  // jinhaiqitodo
  return -1;
}


int main()
{
  vector<char> op_stack;
  vector<int> num_stack;
  //oprator opra;
  string str= "#(1+2)*3#";
  for(int i; i<str.size();)
  {
    char c = str[i];
    switch(chartype(c))
    {
      case 0: // 数字
        {
          num_stack.push_back(c);
          break;
        };
      case 1: // 符号
        {
          if(op_stack.empty() && c != '#')
          {
            cout << "illegal exp!";
            break;
          }
          switch(com(op_stack.back(),c))
          {
            case 1:
            {
              char op = op_stack.back();
              int num1 = num_stack.back();
              num_stack.pop_back();
              int num2 = num_stack.back();
              num_stack.pop_back();
              int rslt = calc(op,num1,num2);
              num_stack.push_back(rslt);


            }
            case -1:
            
            {
            }
            case 0:
            {}
            default:
              {
                cout << "illegal exp!";
                break;
              }
          }
        };
      default:
        {
          cout << "illegal exp!";
          break;
        }
    }
  }

  return 0;
}

