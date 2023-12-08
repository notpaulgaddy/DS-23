#include <iostream>
using namespace std;

int EInString(const string &str, int index)
{
  if (index > str.length())
  {
    return 0;
  }
  if (str[index] == 'E')
  {
    return 1 + EInString(str, index + 1);
  }
  return EInString(str, index + 1);
}

int EInString(const std::string& str){
  return EInString(str,0);
}
void x(){
  cout << "sandwich" << endl;
}
void rec(int iter, int max){
  if(iter<max){
    x();
    rec(iter+1,max);
  }
}
int main()
{
  cout << EInString("EEarthE",0) << endl;
  rec(0,7);
  return 0;
}