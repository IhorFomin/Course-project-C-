// ConsoleApp_Paralele.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <cmath>
//#include <clocale>

using namespace std;

long double fact(int N)
{
    if (N < 0) 
        return 0;
    if (N == 0) 
        return 1; 
    else 
        return N * fact(N - 1); 
}

int main()
{
    int accuracy = 100;
    float value_sin = 3*3.14/2;
    long double sum = 0;
    int thread_count = 1;

    setlocale(LC_CTYPE, "rus"); // русификатор
    cout << "Введите число: ";
    cin >> value_sin;
    cout << "Введите число потоков: ";
    cin >> thread_count;
    unsigned int start_time = clock(); // начальное время

    #pragma omp parallel num_threads(thread_count)
    {
        #pragma omp for
        for (int i = 0; i < accuracy; i++)
        {
            sum = sum + (pow(-1,i)*pow(value_sin,2*i+1)) / fact(2*i+1);
        }
    }
    cout.precision(20);
    cout << "\n" << "Результат работы програмы: " << "\n";
    cout  << sum << "\n";
    cout << "Результат работы встроеного модуля cmath: " << "\n";
    cout << sin(value_sin) << "\n" << "\n";

    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    cout << "Время работи: " << search_time << " мс" << "\n";

    return 0;
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
