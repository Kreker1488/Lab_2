#include "C:\Git\lab_projects_2025\Lab_2\headers\add_to_balance.hpp"

#include <conio.h>
#include <iostream>
#include <string>

void add_to_balance(float& balance_rub, float& balance_usd, float& balance_euw, float& nal_rub_balance, float& nal_usd_balance, float& nal_euw_balance){
    std::cout << "Какой баланс вы хотите пополнить?" << std::endl;
    std::cout << "1. RUB" << std::endl;
    std::cout << "2. USD" << std::endl;
    std::cout << "3. EUW" << std::endl;
    int i;
    std::cin >> i;
    std::cout << "Введите сумму, которую хотите добавить на баланс" << std::endl;

    float count;
    std::cin >> count;
    if ((i == 1) && (count >= 0) && (nal_rub_balance >= count)){
        balance_rub += count;
        nal_rub_balance -= count;
        std::cout << "Ваш баланс был успешно пополнен. Нажмите любую клавишу чтобы продолжить.";
    }
    if ((i == 2) && (count >= 0) && (nal_usd_balance >= count)){
        balance_usd += count;
        nal_usd_balance -= count;
        std::cout << "Ваш баланс был успешно пополнен. Нажмите любую клавишу чтобы продолжить.";
    }
    if ((i == 3) && (count >= 0) && (nal_euw_balance >= count)){
        balance_euw += count;
        nal_euw_balance -= count;
        std::cout << "Ваш баланс был успешно пополнен. Нажмите любую клавишу чтобы продолжить.";
    }
    if ((i > 3) || (i < 1) || count < 0){
        std::cout << "Произошла ошибка" << std::endl;
    }


    
    _getch(); //ждем любую клавишу
}