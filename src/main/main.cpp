#include <iostream>
#include <thread>
#include "uci/uci.hpp"

int main(int argc, char **argv)
{
    uci::start(std::cin, std::cout);
}