#include "C:\Git\lab_projects_2025\Lab_2\headers\generate.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\authorization.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\pinchange.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\add_to_balance.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\cash_out.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\converter.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\change_card.hpp"
#include "C:\Git\lab_projects_2025\Lab_2\headers\exchange_rate.hpp"

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
    std::string rzero1 = "0", rzero2 = "0", rzero3 = "0";
    std::string rub = "RUB";
    std::string dzero1 = "0", dzero2 = "0", dzero3 = "0";
    std::string usd = "USD";
    std::string ezero1 = "0", ezero2 = "0", ezero3 = "0";
    std::string euw = "EUW";

    std::string* cards[3][11] = {
        // Карта 1 - свои переменные
        {&visa, &empty1, &empty2, &empty3, &empty4, &rzero1, &rub, &dzero1, &usd, &ezero1, &euw},
        // Карта 2 - свои переменные  
        {&mastercard, &empty5, &empty6, &empty7, &empty8, &rzero2, &rub, &dzero2, &usd, &ezero2, &euw},
        // Карта 3 - свои переменные
        {&mir, &empty9, &empty10, &empty11, &empty12, &rzero3, &rub, &dzero3, &usd, &ezero3, &euw}
    };

    


    //std::string card; // создаем переменные для генерации данных карты
    std::string pincode;
    std::string card_number;
    std::string cvv;
    std::string period;

    float balance_rub = 0;
    float balance_usd = 0;
    float balance_euw = 0; // создаем переменную с балансом карты, по умолчанию равным нулю

    generate_card(pincode, card_number, cvv, period, cards); // присваиваем переменным значения


    std::cout << "1) " << *cards[0][1] << " " << *cards[0][2] << std::endl;
    std::cout << "2) " << *cards[1][1] << " " << *cards[1][2] << std::endl;
    std::cout << "3) " << *cards[2][1] << " " << *cards[2][2] << std::endl;



    std::cout << "Вам доступно 3 карты: 1 - VISA, 2 - MasterCard, 3 - Мир. Выберите номер карты, с которой хотите работать" << std::endl;

    int card = 0;
    while (true){
        std::cin >> card;
        if ((card <= 3) && (card >= 1)){
            change_card(balance_rub, balance_usd, balance_euw, card, pincode, card_number, cvv, period, cards);
            break;
        }
    }
    
    

    std::cout << "Авторизуйтесь в системе" << std::endl; // Ввод данных для авторизации
    
    std::string user_card_number;
    std::string user_pincode;
    authorization(card_number, pincode, user_card_number, user_pincode);

    float usd_rate = 81.05;
    float euw_rate = 93.93;

    float nal_rub_balance = 2000;
    float nal_usd_balance = 100;
    float nal_euw_balance = 20; // переменные с наличным балансом
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
                std::cout << "Текущий баланс карты составляет:" << std::endl;
                std::cout << std::ceil(balance_rub * 100) / 100  << " RUB" << std::endl;
                std::cout << std::ceil(balance_usd * 100) / 100  << " USD" << std::endl;
                std::cout << std::ceil(balance_euw * 100) / 100  << " EUW" << std::endl;

                std::cout << "Наличный баланс:" << std::endl;
                std::cout << std::ceil(nal_rub_balance * 100) / 100  << " RUB" << std::endl;
                std::cout << std::ceil(nal_usd_balance * 100) / 100  << " USD" << std::endl;
                std::cout << std::ceil(nal_euw_balance * 100) / 100  << " EUW" << std::endl;

                std::cout << "Нажмите любую клавишу чтобы продолжить" << std::endl;
                _getch(); //ждем любую клавишу
                break;
            case 3:
                add_to_balance(balance_rub, balance_usd, balance_euw, nal_rub_balance, nal_usd_balance, nal_euw_balance);
                *cards[card - 1][5] = std::to_string(balance_rub);
                *cards[card - 1][7] = std::to_string(balance_usd);
                *cards[card - 1][9] = std::to_string(balance_euw);
                break;
            case 4:
                cash_out(balance_rub, balance_usd, balance_euw, nal_rub_balance, nal_usd_balance, nal_euw_balance);
                *cards[card - 1][5] = std::to_string(balance_rub);
                *cards[card - 1][7] = std::to_string(balance_usd);
                *cards[card - 1][9] = std::to_string(balance_euw);
                break;
            case 5:
                convert(balance_rub, balance_usd, balance_euw);
                break;
            case 6:
                std::cout << "Вам доступно 3 карты: 1 - VISA, 2 - MasterCard, 3 - Мир. Выберите номер карты, с которой хотите работать" << std::endl;
                while (true){
                    std::cin >> card;
                    if ((card <= 3) && (card >= 1)){
                        change_card(balance_rub, balance_usd, balance_euw, card, pincode, card_number, cvv, period, cards);
                        break;
                    }
                }
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
                exchange_rate(usd_rate, euw_rate);
                std::cout << "1 Доллар = " << usd_rate << " рублей" << std::endl;
                std::cout << "1 Евро = " << euw_rate << " рублей" << std::endl;
                std::cout << "Нажмите любую клавишу чтобы продолжить" << std::endl;
                _getch(); //ждем любую клавишу
                break;
        }
    }
}