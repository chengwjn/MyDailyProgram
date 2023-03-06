//函数如何使用指针来处理数组
//大多数情况下，视数组名为指针
//cookies == &cookies[0]
#include <iostream>
const int Arsize = 8;
int sum_arr(int arr[], int n);
int main()
{
    int cookies[Arsize] = {1, 2, 4, 8, 16, 32, 64, 128};
    std::cout << cookies << " = array address, ";
    std::cout << sizeof cookies << " = sizeof cookies\n";
    int sum = sum_arr(cookies, Arsize);
    std::cout << "Total cookies eaten: " << sum << std::endl;
    sum = sum_arr(cookies, 3);
    std::cout << "First three eaters are " << sum << " cookies.\n";
    sum = sum_arr(cookies + 4, 4); //another lie
    std::cout << "Last four eaters ate " << sum << " cookies.\n";
    return 0;
}
int sum_arr(int arr[], int n)
{
    int total = 0;
    std::cout << arr << " = arr, ";
    std::cout << sizeof arr << " = sizeof arr\n";
    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total;
}