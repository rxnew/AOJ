#include <cctype>
#include <string>
#include <iostream>
using namespace std;
typedef string::const_iterator State;

// 数字
int number(State& it) {
  int result = 0;
  while (isdigit(*it)) {
    result *= 10;
    result += *it - '0';
    ++it;
  }
  return result;
}

int expression(State&);

// 因子
// <factor> ::= '(' <expression> ')' | <number>
int factor(State& it) {
  if (*it == '(') {
    ++it;
    int result = expression(it);
    ++it;
    return result;
  }
  else return number(it);
}

// 項
// <term> ::= <factor> { ( * | / ) <factor> }
int term(State& it) {
  int result = factor(it);
  for (;;) {
    if (*it == '*') {
      ++it;
      result *= factor(it);
    }
    else if (*it == '/') {
      ++it;
      result /= factor(it);
    }
    else break;
  }
  return result;
}

// 式
// <expression> ::= <term> { ( + | - ) <term> }
int expression(State& it) {
  int result = term(it);
  for (;;) {
    if (*it == '+') {
      ++it;
      result += term(it);
    }
    else if (*it == '-') {
      ++it;
      result -= term(it);
    }
    else break;
  }
  return result;
}

int main () {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    State it = line.begin();
    cout << expression(it) << endl;
  }
  return 0;
}
