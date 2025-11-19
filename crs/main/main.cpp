#include "C:\Git\lab_projects_2025\Lab_2\headers\generate.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\authorization.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\pinchange.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\add_to_balance.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\cash_out.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\converter.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\change_card.hpp"

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <cmath>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    std::string visa = "VISA";
    std::string mastercard = "MasterCard";
    std::string mir = "Мир";

    std::string empty1 = "", empty2 = "", empty3 = "";
    std::string empty4 = "", empty5 = "", empty6 = "";
    std::string empty7 = "", empty8 = "", empty9 = "";
    std::string empty10 = "", empty11 = "", empty12 = "";
    std::string zero1 = "0", zero2 = "0", zero3 = "0";
    std::string rub1 = "RUB", rub2 = "RUB", rub3 = "RUB";

    std::string* cards[3][7] = {
        // Карта 1 - свои переменные
        {&visa, &empty1, &empty2, &empty3, &empty4, &zero1, &rub1},
        // Карта 2 - свои переменные  
        {&mastercard, &empty5, &empty6, &empty7, &empty8, &zero2, &rub2},
        // Карта 3 - свои переменные
        {&mir, &empty9, &empty10, &empty11, &empty12, &zero3, &rub3}
    };

    


    //std::string card; // создаем переменные для генерации данных карты
    std::string pincode;
    std::string card_number;
    std::string cvv;
    std::string period;

    float balance = 0; // создаем переменную с балансом карты, по умолчанию равным нулю
    std::string currency = "RUB"; // создаем переменную с валютой пользователя, по умолчанию рубли

    generate_card(pincode, card_number, cvv, period, cards); // присваиваем переменным значения


    std::cout << "1) " << *cards[0][1] << " " << *cards[0][2] << std::endl;
    std::cout << "2) " << *cards[1][1] << " " << *cards[1][2] << std::endl;
    std::cout << "3) " << *cards[2][1] << " " << *cards[2][2] << std::endl;



    std::cout << "Вам доступно 3 карты: 1 - VISA, 2 - MasterCard, 3 - Мир. Выберите номер карты, с которой хотите работать" << std::endl;

    int card;
    std::cin >> card;
    change_card(currency, balance, card, pincode, card_number, cvv, period, cards);
    

    std::cout << "Авторизуйтесь в системе" << std::endl; // Ввод данных для авторизации
    
    std::string user_card_number;
    std::string user_pincode;
    authorization(card_number, pincode, user_card_number, user_pincode);

    
    while (true){
        std::cout << "Список команд:" << std::endl;
        std::cout << "1. Сменить PIN-код" << std::endl;
        std::cout << "2. Посмотреть баланс карты" << std::endl;
        std::cout << "3. Пополнить баланс" << std::endl;
        std::cout << "4. Снять наличные" << std::endl;
        std::cout << "5. Конвертировать валюту" << std::endl;
        std::cout << "6. Сменить карту" << std::endl;
        std::cout << "7. Данные карты" << std::endl;
        std::cout << "8. Статистика валют" << std::endl;

        int choice;
        std::cin >> choice;
        switch(choice){
            case 1:
                pinchange(pincode, user_pincode);
                break;
            case 2:
                std::cout << "Текущий баланс карты составляет " << std::ceil(balance * 100) / 100  << " " << currency << std::endl;
                std::cout << "Нажмите любую клавишу чтобы продолжить" << std::endl;
                _getch(); //ждем любую клавишу
                break;
            case 3:
                add_to_balance(balance, currency);
                *cards[card - 1][5] = std::to_string(balance);
                break;
            case 4:
                cash_out(balance, currency);
                *cards[card - 1][5] = std::to_string(balance);
                break;
            case 5:
                convert(balance, currency);
                *cards[card - 1][6] = currency;
                break;
            case 6:
                std::cout << "Вам доступно 3 карты: 1 - VISA, 2 - MasterCard, 3 - Мир. Выберите номер карты, с которой хотите работать" << std::endl;
                std::cin >> card;
                change_card(currency, balance, card, pincode, card_number, cvv, period, cards);
                authorization(card_number, pincode, user_card_number, user_pincode);
                break;
            case 7:
                std::cout << "Карта: " << *cards[card - 1][0] << ":" << std::endl;
                std::cout << "Номер: " << *cards[card - 1][1] << std::endl;
                std::cout << "Пинкод: " << *cards[card - 1][2] << std::endl;
                std::cout << "CVV: " << *cards[card - 1][3] << std::endl;
                std::cout << "Срок: " << *cards[card - 1][4] << std::endl;
                std::cout << "Нажмите любую клавишу чтобы продолжить" << std::endl;
                _getch(); //ждем любую клавишу
                break;
            case 8:
                std::cout << "1 Доллар = 81 Рубль 5 Копеек" << std::endl;
                std::cout << "1 Евро = 93 Рубля 93 Копейки" << std::endl;
                std::cout << "Нажмите любую клавишу чтобы продолжить" << std::endl;
                _getch(); //ждем любую клавишу
                break;
        }
    }


}