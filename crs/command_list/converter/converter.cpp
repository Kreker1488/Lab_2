#include "C:\Git\lab_projects_2025\Lab_2\headers\converter.hpp"

#include <string>
#include <iostream>
#include <conio.h>

void convert(float& balance, std::string& currency){
    std::cout << "Выберите в какую валюту вы хотите конвертировать деньги:" << std::endl;
    std::cout << "1. RUB" << std::endl;
    std::cout << "2. USD" << std::endl;
    std::cout << "3. EUR" << std::endl;

    int x;
    std::cin >> x;
    switch(x){
        case 1:
            if (currency == "USD"){
                balance *= 81.05;
            }
            if (currency == "EUR"){
                balance *= 93.93;
            }
            currency = "RUB";
            break;
        case 2:
            if (currency == "RUB"){
                balance *= 0.012337;
            }
            if (currency == "EUR"){
                balance *= 1.16;
            }
            currency = "USD";
            break;
        case 3:
            if (currency == "RUB"){
                balance *= 0.010646;
            }
            if (currency == "USD"){
                balance *= 0.8638;
            }
            currency = "EUR";
            break;
    }

    std::cout << "Валюта была успешно конвертирована. Нажмите любую клавишу чтобы продолжить." << std::endl;
    _getch(); //ждем любую клавишу
}