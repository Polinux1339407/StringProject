#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "String.h"

void Tests()
{
    String str = String("Hi, Barbie!");
    std::cout << "Конструктор c-style строки: " << str << std::endl;
    std::cout << "Длинна: " << str.length() << std::endl;
    
    String strAssm = str;
    std::cout << "Оператор присваивания = (String): " << strAssm << std::endl;

    const char* cString = "Hi, Ken!";
    strAssm = cString;
    std::cout << "Оператор присваивания = (C-style string): " << strAssm << std::endl;

    String strCopy = String(str);
    std::cout << "Конструктор копирования: " << strCopy << std::endl;

    String strInc = str + String(" Hi, Ken!");
    std::cout << "Оператор конкатенации + (String): " << strInc << std::endl;

    strInc = str + new char[] { " Hi, Ken!" };
    std::cout << "Оператор конкатенации + (C-style string): " << strInc << std::endl;

    str += String(" Hi, Ken!");
    std::cout << "Оператор конкатенации += (String): " << str << std::endl;

    str = String("Hello");
    str += new char[] { " world!" };
    std::cout << "Оператор конкатенации += (C-style string): " << str << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "rus");
    std::vector<String> strings;
    std::string line;
    std::ifstream input("input.txt");

    Tests();

    if (input.is_open()) 
    {
        while (std::getline(input, line))
        {
            if (line != "")
                strings.push_back(String(line.c_str()));
        }
    }
    input.close();

    std::sort(strings.begin(), strings.end(), std::greater<String>());

    std::ofstream output("output.txt");
    if (output.is_open())
    {
        for (const auto& str : strings)
        {
            std::cout << str << std::endl;
            output << str << std::endl;
        }
    }
    output.close();

    system("pause");
    return 0;
}
