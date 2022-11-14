﻿// Lab8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Header.h"

template <typename T>
std::ostream& operator<<(std::ostream& os, std::list<T> list)
{
    for (const T& var : list)
    {
        os << var << ' ';
    }
    os << '\n';
    return os;

};

void PrintGraph(std::vector<std::list<int>> graph)
{
    for (int i = 0; i < graph.size(); i++)
        std::cout << i << ": " << graph[i];
}

int main()
{
    /*std::cout << "Create file?(yes\\no)\n";
    std::string ans;
    std::cin >> ans;
    if (ans == "yes")
        CreateFile();*/
        

    auto graph = ReadFile();

    //PrintGraph(CountConnectivityComponent(graph));

    PrintGraph(ShotestDistance(graph, 4));

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
