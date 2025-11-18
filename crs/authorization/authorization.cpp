#include "C:\Git\lab_projects_2025\Lab_2\headers\authorization.hpp"

#include <iostream>
#include <string>

void authorization(std::string card_number, std::string pincode, std::string& user_card_number, std::string& user_pincode){
    do {
            std::cout << "Введите номер карты: " << std::endl;
            std::cin >> user_card_number;
            std::cout << "Введите PIN-код:" << std::endl;
            std::cin >> user_pincode;
            if ((user_card_number == card_number) && (user_pincode == pincode)){
                std::cout << "Поздравляю, вы успешно авторизовались" << std::endl;
                break;
            }
            else{
                std::cout << "Неверные данные, попробуйте снова" << std::endl; 
            }
        } while (true);
    }