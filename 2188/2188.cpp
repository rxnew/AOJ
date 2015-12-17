#include <iostream>
#include <sstream>
#include <unordered_map>
#define REP(i, n) for(int i = 0; i < (int)n; i++)

using namespace std;

unordered_map<string, int> pres = {
  {"yotta", 24}, {"zetta", 21},  {"exa", 18},   {"peta", 15},   {"tera", 12},
  {"giga", 9},   {"mega", 6},    {"kilo", 3},   {"hecto", 2},   {"deca", 1},
  {"deci", -1},  {"centi", -2},  {"milli", -3}, {"micro", -6},  {"nano", -9},
  {"pico", -12}, {"femto", -15}, {"ato", -18},  {"zepto", -21}, {"yocto", -24},
  {"none", 0},
};

string convert(string& num, string& pre, string& uni) {
  int dp = num.find(".");
  int msd = num.find_first_not_of("0.") - ((num.front() != '0')? 0: 1);
  int sd = num.size() - msd - ((dp == string::npos)? 0: 1);
  int mul = (dp == string::npos)? sd - 1: dp - msd - 1;
  if(dp != string::npos) num.erase(dp, 1);
  if(msd + 1 < num.size()) num.insert(msd + 1, 1, '.');
  num.erase(0, msd);
  ostringstream oss;
  oss << num << " * 10^" << mul + pres[pre] << " " << uni;
  return oss.str();
}

int main() {
  int n;
  cin >> n;
  REP(i, n) {
    string num, pre, uni;
    cin >> num >> pre;
    if(pres.find(pre) != pres.end()) cin >> uni;
    else uni = pre, pre = "none";
    cout << convert(num, pre, uni) << endl;
  }
  return 0;
}
