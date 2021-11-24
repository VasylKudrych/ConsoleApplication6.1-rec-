// 6.1.cpp - рекурс≥€

#include <iostream>
#include<iomanip>

using namespace std;

void print1(int* p, const int n, int i)
{
    cout << setw(3) << p[i];
    if (i < n - 1)
        print1(p, n, i + 1);                    
    else
        cout << '\n';
}

void format_mas(int* p, int n, int& sum, int& k, int i)
{
    if (i < n)
    {
        if ((p[i] > 0) || p[i] % 2 == 0) // !(p[i] > 0 == 0) Ц вс≥ додатн≥; p[i] % 2 == 0 - з парним ≥ндесом
        {
            k++;
            sum += p[i];
            p[i] = 0;
        }
        format_mas(p, n, sum, k, i + 1);
    
    
        
    }
}

void print0(int* p, const int n, int i)
{
    cout << setw(3) << p[i];
    if (i < n - 1)
        print0(p, n, i + 1);
    else
        cout << '\n';
}

void create(int* p, const int size, const int Low, const int High, int i)
{
    p[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        create(p, size, Low, High, i + 1);
}

int main()
{
    
  srand(unsigned(time(NULL))); // ≥н≥ц≥ал≥зац≥€ генератора випадкових чисел

    const int n = 24;
    int p[n];
    int sum = 0;
    int k = 0;
    create(p, n, -10, 14, 0); // створюЇмо масив

    cout << setw(3) << "p[] = ";
    print0(p, n, 0); // виводимо його
    format_mas(p, n, sum, k, 0); // опрацьовуЇмо

    cout << setw(3) << "p[] = ";
    print1(p, n, 0); // виводимо 
    cout << '\n';
    cout << "quantity - " << k << '\n';
    cout << "sum - " << setw(8) << sum << '\n';
    cout << '\n';
}
