#include "C:\Git\lab_projects_2025\Lab_2\headers\change_card.hpp"

void change_card(std::string& currency, float& balance, int card, std::string& pincode, std::string& card_number, std::string& cvv, std::string& period, std::string* cards[3][7]){
    pincode = *cards[card - 1][2];
    card_number = *cards[card - 1][1];
    cvv = *cards[card - 1][3];
    period = *cards[card - 1][4];
    balance = std::stof(*cards[card - 1][5]);
    currency = *cards[card - 1][6];
    
}