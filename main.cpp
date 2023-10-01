#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
using namespace std;
int main() {
  while (true) {
  int choice;
  cout << "Выберите номер задачи: " << endl;
  cout << "1. Информация об объеме типов данных на этом компьютере." << endl;
  cout << "2. Двоичное представление целого числа в памяти." << endl;
  cout << "3. Двоичное представление типа float в памяти." << endl;
  cout << "4. Двоичное представление типа double в памяти." << endl;
  cout << "Введите номер выбранной задачи (1/2/3/4) или нажмите CTRL+C для выхода:" << endl;
  cin >> choice;
  if (choice == 1){
  // task 1
  cout << "int занимает " << sizeof(int) << " bytes" << endl;
  cout << "short int takes " << sizeof(short) << " bytes" << endl;
  cout << "long int takes " << sizeof(long) << " bytes" << endl;
  cout << "float takes " << sizeof(float) << " bytes" << endl;
  cout << "double takes " << sizeof(double) << " bytes" << endl;
  cout << "char takes " << sizeof(char) << " bytes" << endl;
  cout << "bool takes " << sizeof(bool) << " bytes" << endl;
  }
  else if (choice == 2) {
  // task 2
  int inputInt;
  cin >> inputInt;
  int lengthInt = sizeof(int)*8;
  unsigned int mask = 1 << (lengthInt - 1); 
  unsigned int currentBit; 
  for (int i = 0; i < lengthInt; i++) {
    currentBit = inputInt & mask;
    currentBit = currentBit >> (lengthInt - i - 1); 
    mask = mask >> 1; 
    cout << currentBit;
    if (i == 0 || (i+1) % 8 == 0) 
      cout << ' ';
  }
  cout << endl;
  }
  else if (choice == 3) {
  // task 3
  union {
  float inputFloat;
  int interlayer;
  }; 
  cin >> inputFloat;
  int lengthFloat = sizeof(float)*8;
  unsigned int mask = 1 << (lengthFloat - 1);
  unsigned int currentBit;
  for (int i = 0; i < lengthFloat; i++) {
    currentBit = interlayer & mask;
    currentBit = currentBit >> (lengthFloat - i - 1);
    mask = mask >> 1;
    cout << currentBit;
    if (i == 0 || i == 8)
      cout << ' ';
  }
  cout << endl;
  }
  else if (choice == 4) {
  // task 4
  union {
  double inputDouble;
  unsigned int arrLayer[2];  }; 
  cin >> inputDouble;
  for (int i = 1; i >= 0; --i) { 
    unsigned int mask = 1 << 31;
    unsigned int currentBit = 0;
    int lengthInt = sizeof(int)*8;
    for (int j = 0; j < lengthInt; ++j) {
      currentBit = arrLayer[i] & mask;
      mask = mask >> 1;
      currentBit = currentBit >> (lengthInt - 1- j);
      cout << currentBit;
      if (i == 1 && j == 0)
        cout << ' ';
      if (i == 1 && j == 11)
        cout << ' ';
    }
  }
  cout << endl;
  }
  else {
    cout << "Кажется, вы ввели не верное значение, попробуйте снова" << endl;
  }
  }
  cout << '#' <<  endl;
  return 0;
}

