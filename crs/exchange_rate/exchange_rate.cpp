#include "C:\Git\lab_projects_2025\Lab_2\headers\exchange_rate.hpp"

#include <cstdlib>

void exchange_rate(float& usd_rate, float& euw_rate){
    usd_rate = 81.05;
    euw_rate = 93.93;
    usd_rate += (rand() % 10 - 7);
    euw_rate += (rand() % 10 - 7);
}