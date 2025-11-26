#include "C:\Git\lab_projects_2025\Lab_2\headers\change_card.hpp"

void change_card(float& balance_rub, float& balance_usd, float& balance_euw, int card, std::string& pincode, std::string& card_number, std::string& cvv, std::string& period, std::string* cards[3][11]){
    pincode = *cards[card - 1][2];
    card_number = *cards[card - 1][1];
    cvv = *cards[card - 1][3];
    period = *cards[card - 1][4];
    balance_rub = std::stof(*cards[card - 1][5]);
    balance_usd = std::stof(*cards[card - 1][7]);
    balance_euw = std::stof(*cards[card - 1][9]);
    
}