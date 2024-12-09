// main.cpp

#include "balancingbot.h";

#include <exception>
#include <format>
#include <iostream>
#include <memory>

int main() {

    std::cout << "Starting trading application" << std::endl;

    std::shared_ptr<BalancingBot> balancingBot = std::make_shared<BalancingBot>();

    try {
        balancingBot->run();
    }
    catch (std::runtime_error& e) {
        std::cout << std::format("Exception^ {}", e.what()) << std::endl;
    }
   
    return 0;
}
