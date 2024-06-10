#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "String.h"

void run_tests()
{
    String str = String("Hi, Barbie!");
    std::cout << "C-style string constructor: " << str << std::endl;
    std::cout << "Конструктор c-style строки: " << str << std::endl;
    std::cout << "Length: " << str.length() << std::endl;
    std::cout << "Длинна: " << str.length() << std::endl;
    
    String str_copy = String(str);
    std::cout << "Copy Constructor: " << str_copy << std::endl;
    std::cout << "Конструктор копирования: " << str_copy << std::endl;

    String str_ass_copy = str;
    std::cout << "Operator = (String): " << str_ass_copy << std::endl;

    const char* c_string = "Hi, Ken!";
    str_ass_copy = c_string;
    std::cout << "Operator = (C-style string): " << str_ass_copy << std::endl;

    String str_inc = str + String(" Hi, Ken!!");
    std::cout << "Operator + (String): " << str_inc << std::endl;

    str_inc = str + new char[] { " Hi, Ken!" };
    std::cout << "Operator + (C-style string): " << str_inc << std::endl;

    str += String(" Hi, Ken!");
    std::cout << "Operator += (String): " << str << std::endl;

    str = String("Hello");
    str += new char[] { " world!" };
    std::cout << "Operator += (C-style string): " << str << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "rus");
    std::vector<String> strings;
    std::string line;
    std::ifstream input("input.txt");

    if (input.is_open()) //проверка коммента
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

    //run_tests();

    system("pause");
    return 0;
}
