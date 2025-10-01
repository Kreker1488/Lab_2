#include <iostream>
#include <string>
#include <bitset>
#include <cmath>


int main() {

    setlocale(LC_ALL, "Russian");
    int gold;
    int silver;
    std::cout << "Enter the number of gold coins :" << std::endl;
    std::cin >> gold;
    std::cout << "Enter the number of silver coins :" << std::endl;
    std::cin >> silver;

    int cost = 50;
    int count_bottles = 10;

    int bought;
    std::cout << "How many bottles do you need? :" << std::endl;
    std::cin >> bought;

    int coins_left;
    coins_left = (gold * 100 + silver) - (bought * cost);

    int bottles_left;
    bottles_left = count_bottles - bought;

    gold = coins_left / 100;
    silver = coins_left % 100;

    std::cout << "You have " << gold << " gold coins and " << silver << " silver coins." << std::endl;
    std::cout << bottles_left << " bottles left." << std::endl;
    std::cout << "You have got " << bought << " bottles." << std::endl;
    


    //Задание 4 вариант
    

    int const a = std::log2(coins_left) + 1;
    
    
    std::cout << "Binary recording of the remaining coins:" << std::endl;
    std::bitset<16> bin_num = coins_left;
    std::cout << bin_num.to_string().substr(16 - a) << std::endl;
    std::cout << a << " - number of digits" << std::endl;
    
    


}