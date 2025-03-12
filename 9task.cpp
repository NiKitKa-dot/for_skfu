#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <random>


using namespace std;

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    int a[100];
    for (int i = 0; i < 100; i++) {
        a[i] = rand()%222 + 33;
    }
    fstream out1("C:/Users/ygv08/OneDrive/Рабочий стол/txt.bin", ios::binary | ios::out);

    if (out1.is_open())
    {
        out1.write((char*)&a, sizeof(a));
    }

    out1.close();


    cout << "before\n" << endl;


    int a1[100]{ 0 };
    fstream aut("C:/Users/ygv08/OneDrive/Рабочий стол/txt.bin", ios::binary | ios::in);

    if (aut.is_open()) {
        aut.read((char*)a1, sizeof(a));
    }
    aut.close();
    for (int c = 0; c < size(a1); c++)
        cout << a1[c] << " ";
    
    char c1[100] {};

 
    for (int i = 0; i < 100; i++) {
        c1[i] = static_cast<char>(a[i]);
    }

    cout << "\n\nafter\n" << endl;
    //записываем числа преобразовав их в тип char
    fstream out2("C:/Users/ygv08/OneDrive/Рабочий стол/txt.bin", ios::out | ios::binary | ios::trunc);

    if (out2.is_open())
    {
        out2.write(c1, sizeof(c1));
    }
    out2.close();
    char c2[100]{};
    fstream aut2("C:/Users/ygv08/OneDrive/Рабочий стол/txt.bin", ios::binary | ios::in);

    if (aut2.is_open()) {
        aut2.read((char*)c2, sizeof(c1));
    }
    aut2.close();
    for (int c = 0; c < size(c2); c++)
        cout << c2[c] << " ";
}
