#include "C:\Git\lab_projects_2025\Lab_2\headers\pinchange.hpp"

#include <iostream>
#include <string>
#include <conio.h>
#include <unordered_set>

void pinchange(std::string& pincode, std::string& user_pincode){
    std::cout << "Введите старый PIN-код:" << std::endl;
    std::cin >> user_pincode;

    if (user_pincode == pincode){
        std::cout << "Введите новый PIN-код" << std::endl;
        std::string flag_code;
        std::cin >> flag_code;

        bool flag = true;
        if (std::size(flag_code) != 4){
            std::cout << "Ошибка, PIN-код должен содержать ровно 4 цифры.";
            flag = false;
        }

        std::unordered_set<char> unique_digits; // создаем множество элементов
        for (char c : flag_code) { // пробегаем по пинкоду
            if (!std::isdigit(c)){ // есди найдена НЕцифра то вывести ошибку
                std::cout << "Ошибка, PIN-код должен содержать только цифры.";
                flag = false;
            };
            unique_digits.insert(c); // добавляем все элементы в множество
        }
        if (unique_digits.size() == 1){
            std::cout << "Ошибка, PIN-код должен содержать неодинаковые цифры.";
            flag = false;
        }
        if ((flag_code == "0123") || (flag_code == "1234")){
            std::cout << "Ошибка, PIN-код слишком простой.";
            flag = false;
        } 
        if (flag){
            std::cout << "Ваш PIN-код был успешно изменен" << std::endl;
            pincode = flag_code;
        }
    }
    else{
        std::cout << "Неверный PIN-код" << std::endl;
    }
    std::cout << "Нажмите любую клавишу чтобы продолжить" << std::endl;
    _getch(); //ждем любую клавишу
}