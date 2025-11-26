#include "C:\Git\lab_projects_2025\Lab_2\headers\generate.hpp"

#include <iostream>
#include <string>
#include <cstdlib>


void lunh(std::string& card_number){
    for (int i = 0; i < 15; i++){
        card_number += std::to_string(rand() % 10);
    }

    // Алгоритм Луна для расчета контрольной цифры
    int sum = 0;
    bool flag = true;
    for (int i = card_number.length() - 1; i >= 0; i--) {
        int digit = card_number[i] - '0'; //прикольный способ перевести строку в число
        if (flag) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }
        sum += digit;
        flag = !flag;
    }
    
    int checkDigit = (10 - (sum % 10)) % 10;
    card_number[15] = '0' + checkDigit; // Заменяем последнюю цифру
}

void generate_card(std::string& pincode, std::string& card_number, std::string& cvv, std::string& period, std::string* cards[3][11]){
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

    // генерируем номер карты visa
    card_number = "4" + card_number;
    lunh(card_number);
    *cards[0][1] = card_number;
    card_number = "";
    

    // генерируем номер карты мастеркард
    card_number = "5" + card_number;
    lunh(card_number);
    *cards[1][1] = card_number;
    card_number = "";

    // генерируем номер карты МИР
    card_number = "2" + card_number;
    lunh(card_number);
    *cards[2][1] = card_number;
    card_number = "";
    

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