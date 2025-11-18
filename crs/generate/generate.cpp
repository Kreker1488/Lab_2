#include "C:\Git\lab_projects_2025\Lab_2\headers\generate.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

void generate_card(std::string& pincode, std::string& card_number, std::string& cvv, std::string& period, std::string* cards[3][7]){
    srand(time(NULL)); //Добавляем рандом

    /*std::string card_forms[3] = {"VISA", "MasterCard", "Мир"}; //создаем массив с названиями карт, просто для удобства в выводе
    card = card_forms[card_format - 1];*/

    // генерируем пинкод
    for (int j = 0; j < 3; j++){
        pincode = ""; 
        for (int i = 0; i < 4; i++){
            pincode += std::to_string(rand() % 10);
        }
        *cards[j][2] = pincode;
    }

    // генерируем номер карты
    for (int j = 0; j < 3; j++){
        card_number = "";
        for (int i = 0; i < 16; i++){
            /*if ((i == 3) || (i == 7) || (i == 11));{ // каждые 4 сиволы ставим пробел для удобства чтения
                card_number += std::to_string(rand() % 10);
                card_number += " ";
            }*/
            card_number += std::to_string(rand() % 10);
        }
        *cards[j][1] = card_number;
    }

    // генерируем cvv код
    for (int j = 0; j < 3; j++){
        cvv = "";
        for (int i = 0; i < 3; i++){
            cvv += std::to_string(rand() % 10);
        }
        *cards[j][3] = cvv;
    }

    // генерируем случайный месяц для срока годности карты
    for (int j = 0; j < 3; j++){
        for (int j = 0; j < 3; j++){
            period = "";
            
            // Генерируем месяц (1-12)
            int month = rand() % 12 + 1;
            
            // Добавляем ведущий ноль если месяц < 10
            if (month < 10) {
                period += "0";
            }
            period += std::to_string(month);
            
            period += "/35"; // год фиксированный
            
            *cards[j][4] = period;
        }       
    }
    
}