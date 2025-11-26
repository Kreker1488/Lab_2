#include "C:\Git\lab_projects_2025\Lab_2\headers\cash_out.hpp"

#include <conio.h>
#include <iostream>
#include <string>

void cash_out(float& balance_rub, float& balance_usd, float& balance_euw, float& nal_rub_balance, float& nal_usd_balance, float& nal_euw_balance){
    std::cout << "Какой баланс вы хотите оббналичить?" << std::endl;
    std::cout << "1. RUB" << std::endl;
    std::cout << "2. USD" << std::endl;
    std::cout << "3. EUW" << std::endl;
    int i;
    std::cin >> i;


    std::cout << "Введите сумму, которую хотите вывести со счета" << std::endl;
    float count;
    std::cin >> count;
    if ((i == 1) && (count >= 0) && (balance_rub >= count)){
        balance_rub -= count;
        nal_rub_balance += count;
        std::cout << "Вы успешно сняли деньги с вашего счета. Нажмите любую клавишу чтобы продолжить.";
    }
    if ((i == 2) && (count >= 0) && (balance_usd >= count)){
        balance_usd -= count;
        nal_usd_balance += count;
        std::cout << "Вы успешно сняли деньги с вашего счета. Нажмите любую клавишу чтобы продолжить.";
    }
    if ((i == 3) && (count >= 0) && (balance_euw >= count)){
        balance_euw -= count;
        nal_euw_balance += count;
        std::cout << "Вы успешно сняли деньги с вашего счета. Нажмите любую клавишу чтобы продолжить.";
    }
    else{
        std::cout << "Произошла ошибка" << std::endl;
    }
    

    std::cout << "Нажмите любую клавишу чтобы продолжить.";
    _getch(); //ждем любую клавишу
}