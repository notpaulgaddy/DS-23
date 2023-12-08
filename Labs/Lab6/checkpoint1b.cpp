#include <iostream>
#include <string>
#include <vector>

template <class T>
void print(std::vector<T> &data, const std::string &label) {
  std::cout << label << " ";
  for (typename std::vector<T>::iterator it = data.begin(); it != data.end(); it++) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
}

template <class T>
void reverse(std::vector<T> &data) {
  typename std::vector<T>::iterator begin = data.begin();
  typename std::vector<T>::iterator end = data.end() - 1;
  while (begin < end) {
    T temp = *begin;
    *begin = *end;
    *end = temp;
    begin++;
    end--;
  }
}

int main() {
  std::vector<int> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(5);
  data.push_back(6);
  data.push_back(7);

  print(data,"before:");
  reverse(data);
  print(data,"after: ");

  std::vector<std::string> data2;
  data2.push_back("apple");
  data2.push_back("banana");
  data2.push_back("carrot");
  data2.push_back("date");

  print(data2,"before:");
  reverse(data2);
  print(data2,"after: ");
}
