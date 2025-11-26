#include "C:\Git\lab_projects_2025\Lab_2\headers\converter.hpp"

#include <string>
#include <iostream>
#include <conio.h>

void convert(float& balance_rub, float& balance_usd, float& balance_euw){
    std::cout << "Какой баланс вы хотите конвертировать?" << std::endl;
    std::cout << "1. RUB" << std::endl;
    std::cout << "2. USD" << std::endl;
    std::cout << "3. EUW" << std::endl;
    int i;
    std::cin >> i;


    std::cout << "Выберите в какую валюту вы хотите конвертировать деньги:" << std::endl;
    std::cout << "1. RUB" << std::endl;
    std::cout << "2. USD" << std::endl;
    std::cout << "3. EUR" << std::endl;
    int x;
    std::cin >> x;

    std::cout << "Укажите сумму для конвертации" << std::endl;
    float count;
    std::cin >> count;

    switch(x){
        case 1:
            if (i == 2){
                balance_usd -= count;
                if (balance_usd < 0){
                    std::cout << "Произошла ошибка" << std::endl;
                    balance_usd += count;
                }
                else{
                    balance_rub += count * 81.05 + (rand() % 10 - 7);
                    std::cout << "Валюта была успешно конвертирована. Нажмите любую клавишу чтобы продолжить." << std::endl;
                }
            }
            if (i == 3){
                balance_euw -= count;
                if (balance_euw < 0){
                    std::cout << "Произошла ошибка" << std::endl;
                    balance_euw += count;
                }
                else{
                    balance_rub += count * 93.93 * (rand() % 10 - 7);
                    std::cout << "Валюта была успешно конвертирована. Нажмите любую клавишу чтобы продолжить." << std::endl;
                }
            }
            break;
        case 2:
            if (i == 1){
                balance_rub -= count;
                if (balance_rub < 0){
                    std::cout << "Произошла ошибка" << std::endl;
                    balance_rub += count;
                }
                else{
                    balance_usd += count * 0.012337;
                    std::cout << "Валюта была успешно конвертирована. Нажмите любую клавишу чтобы продолжить." << std::endl;
                }
            }
            if (i == 3){
                balance_euw -= count;
                if (balance_euw < 0){
                    std::cout << "Произошла ошибка" << std::endl;
                    balance_euw += count;
                }
                else{
                    balance_usd += count * 1.16;
                    std::cout << "Валюта была успешно конвертирована. Нажмите любую клавишу чтобы продолжить." << std::endl;
                }
            }
            break;
        case 3:
            if (i == 1){
                balance_rub -= count;
                if (balance_rub < 0){
                    std::cout << "Произошла ошибка" << std::endl;
                    balance_rub += count;
                }
                else{
                    balance_euw += count * 0.010646;
                    std::cout << "Валюта была успешно конвертирована. Нажмите любую клавишу чтобы продолжить." << std::endl;
                }
            }
            if (i == 2){
                balance_usd -= count;
                if (balance_usd < 0){
                    std::cout << "Произошла ошибка" << std::endl;
                    balance_usd += count;
                }
                else{
                    balance_euw += count * 0.8638;
                    std::cout << "Валюта была успешно конвертирована. Нажмите любую клавишу чтобы продолжить." << std::endl;
                }
            }
            break;
    }

    
    _getch(); //ждем любую клавишу
}