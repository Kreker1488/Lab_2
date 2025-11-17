#include "C:\Git\lab_projects_2025\Lab_2\headers\authorization.hpp"

#include <iostream>
#include <string>

bool authorization(std::string card_number, std::string pincode, std::string user_card_number, std::string user_pincode){
    if ((user_card_number == card_number) && (user_pincode == pincode)){
        return true;
    }
    return false;
}