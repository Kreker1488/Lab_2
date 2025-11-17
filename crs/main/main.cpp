#include "C:\Git\lab_projects_2025\Lab_2\headers\generate.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\authorization.hpp"

#include <iostream>
#include <Windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Выберите формат карты, который вы хотите:" << std::endl; //вывводим пользователю окно с выбором формата карты
    std::cout << "1. VISA" << std::endl;
    std::cout << "2. MasterCard" << std::endl;
    std::cout << "3. Мир" << std::endl;

    int card_format; //запоминаем выбранный формат карты
    std::cin >> card_format;

    std::string card; // создаем переменные для генерации данных карты
    std::string pincode;
    std::string card_number;
    std::string cvv;
    std::string period;

    generate_card(card, pincode, card_number, cvv, period, card_format); // присваиваем переменным значения

    std::cout << "Вы выбрали карту " << card << std::endl; // Вывод сведений о формате карты, нмоере и пинкоде
    std::cout << "Ваш номер карты: " << card_number << std::endl;
    std::cout << "Ваш PIN-код: " << pincode << std::endl;
    std::cout << "Авторизуйтесь в системе" << std::endl; // Ввод данных для авторизации
    

    do {
        std::cout << "Введите номер карты: " << std::endl;
        std::string user_card_number;
        std::cin >> user_card_number;
        std::cout << "Введите PIN-код:" << std::endl;
        std::string user_pincode;
        std::cin >> user_pincode;
        if (authorization(card_number, pincode, user_card_number, user_pincode)){
            std::cout << "Поздравляю, вы успешно авторизовались" << std::endl;
            break;
        }
        else{
            std::cout << "Неверные данные, попробуйте снова" << std::endl; 
        }
    } while (true);
}