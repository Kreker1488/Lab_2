#include "C:\Git\lab_projects_2025\Lab_2\headers\generate.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

void generate_card(std::string& card, std::string& pincode, std::string& card_number, std::string& cvv, std::string& period, int card_format){
    srand(time(NULL)); //Добавляем рандом

    std::string cards[3] = {"VISA", "MasterCard", "Мир"}; //создаем массив с названиями карт, просто для удобства в выводе
    card = cards[card_format - 1];

    // генерируем пинкод
    for (int i = 0; i < 4; i++){
        pincode += std::to_string(rand() % 10);
    }

    // генерируем номер карты
    for (int i = 0; i < 16; i++){
        /*if ((i == 3) || (i == 7) || (i == 11));{ // каждые 4 сиволы ставим пробел для удобства чтения
            card_number += std::to_string(rand() % 10);
            card_number += " ";
        }*/
        card_number += std::to_string(rand() % 10);
    }

    // генерируем cvv код
    for (int i = 0; i < 3; i++){
        cvv += std::to_string(rand() % 10);
    }

    // генерируем случайный месяц для срока годности карты
    for (int i = 0; i < 2; i++){
        period += std::to_string(rand() % 12);
    }
    period += "/35"; // отделяем месяц от года и продливаем на 10 лет
}