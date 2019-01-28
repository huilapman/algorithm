#include <algorithm>
#include <vector>
#include <string>
class Person {
public:
  std::string m_name;
  int m_id;
  Person(std::string name, int id) :
    m_name(name), m_id(id) {
  }
  bool operator <(const Person & obj) {
    if (m_id < obj.m_id)
      return true;
    else
      return false;
  }
};
 
struct PersonCompartor {
  bool operator()(const Person & first, const Person & sec) {
    if (first.m_name < sec.m_name)
      return true;
    else
      return false;
  }
};
 
int main() {
  int arr[] = { 1, 3, 2, 8, 6, 7, 5 };
  int len = sizeof(arr) / sizeof(int);

  std::sort(arr, arr + len);

  for (int i = 0; i < len; i++)
    std::cout << arr[i] << " , ";
  std::cout << std::endl;

  std::vector<std::string> vecOfStrings;

  vecOfStrings.push_back("bbb");
  vecOfStrings.push_back("fff");
  vecOfStrings.push_back("aaa");
  vecOfStrings.push_back("ccc");
  vecOfStrings.push_back("abc");

  std::sort(vecOfStrings.begin(), vecOfStrings.end());

  std::for_each(vecOfStrings.begin(), vecOfStrings.end(), [](std::string str) {
    std::cout<<str<< " , ";
  });

  std::cout << std::endl;

  std::vector<Person> vecOfPersons = { Person("aaa", 7), Person("kkk", 3),
    Person("ddd", 5), Person("abc", 2) };

  std::sort(vecOfPersons.begin(), vecOfPersons.end());

  std::cout << "Sorted Persons List based on ID\n";
  std::for_each(vecOfPersons.begin(), vecOfPersons.end(), [](Person & obj) {
    std::cout<<obj.m_id<< " :: "<<obj.m_name<<std::endl;
  });

  std::sort(vecOfPersons.begin(), vecOfPersons.end(), PersonCompartor());

  std::cout << "Sorted Persons List based on Name using Func Object\n";
  std::for_each(vecOfPersons.begin(), vecOfPersons.end(), [](Person & obj) {
    std::cout<<obj.m_id<< " :: "<<obj.m_name<<std::endl;
  });

  std::cout << "Sorted Persons List based on Name using Lamba\n";
  std::sort(vecOfPersons.begin(), vecOfPersons.end(), [](const Person & first, const Person & sec) {
    if (first.m_name < sec.m_name)
      return true;
    else
      return false;
  });

  std::cout << "Sorted Persons List based on Name\n";
  std::for_each(vecOfPersons.begin(), vecOfPersons.end(), [](Person & obj) {
    std::cout<<obj.m_id<< " :: "<<obj.m_name<<std::endl;
  });
 
  return 0;
}
