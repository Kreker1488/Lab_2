cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME labwork_4)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

add_executable("${PROJECT_NAME}" crs/main/main.cpp crs/generate/generate.cpp crs/authorization/authorization.cpp crs/command_list/pin_change/pinchange.cpp crs/command_list/check_balance/add_to_balance.cpp crs/command_list/cash_out/cash_out.cpp crs/command_list/converter/converter.cpp crs/command_list/change_card/change_card.cpp crs/exchange_rate/exchange_rate.cpp)



