#include "C:\Git\lab_projects_2025\Lab_2\headers\cash_out.hpp"

#include <conio.h>
#include <iostream>
#include <string>

void cash_out(float& balance, std::string currency){
    std::cout << "Введите сумму, которую хотите вывести со счета. Сумма должна быть указана в " << currency << std::endl;
    float i;
    std::cin >> i;

    if (balance >= i){
        balance -= i;
        std::cout << "Вы успешно сняли деньги с вашего счета." << std::endl;
    }
    else{
        std::cout << "На вашем счете недостаточно средств" << std::endl;
    }
    

    std::cout << "Нажмите любую клавишу чтобы продолжить.";
    _getch(); //ждем любую клавишу
}