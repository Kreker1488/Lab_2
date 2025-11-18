#include "C:\Git\lab_projects_2025\Lab_2\headers\add_to_balance.hpp"

#include <conio.h>
#include <iostream>
#include <string>

void add_to_balance(float& balance, std::string currency){
    std::cout << "Введите сумму, которую хотите добавить на баланс. Сумма должна быть указана в " << currency << std::endl;
    float i;
    std::cin >> i;
    balance += i;

    std::cout << "Ваш баланс был успешно пополнен. Нажмите любую клавишу чтобы продолжить.";
    _getch(); //ждем любую клавишу
}