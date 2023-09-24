#include <iostream>
#include <iterator>
using namespace std;
int main() {
  // task 1
  cout << "int takes " << sizeof(int) << " bytes" << endl;
  cout << "short int takes " << sizeof(short) << " bytes" << endl;
  cout << "long int takes " << sizeof(long) << " bytes" << endl;
  cout << "float takes " << sizeof(float) << " bytes" << endl;
  cout << "double takes " << sizeof(double) << " bytes" << endl;
  cout << "char takes " << sizeof(char) << " bytes" << endl;
  cout << "bool takes " << sizeof(bool) << " bytes" << endl;

  // task 2
  int inputInt;
  cin >> inputInt;
  int lengthInt = sizeof(int)*8;
  unsigned int mask = 1 << (lengthInt - 1); // маска для получения значения бита вида 100..00 где нулей 31
  unsigned int currentBit; // значение данного бита
  for (int i = 0; i < lengthInt; i++) {
    currentBit = inputInt & mask;// побитовой конъюнкцией получаем значение данного бита
    currentBit = currentBit >> (lengthInt - i - 1); // сдвигаем 100..0 до 00.01
    mask = mask >> 1; // сдвигаем маску на 1 бит вправо
    cout << currentBit;
    if (i == 0 || (i+1) % 8 == 0) // осуществляем отступы
      cout << ' ';
  }
  cout << endl;

  // task 3
  union {
  float inputFloat;
  int interlayer;
  }; // подменяем флоат на инт
  cin >> inputFloat;
  int lengthFloat = sizeof(float)*8;
  mask = 1 << (lengthFloat - 1);
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

