#include <gtest/gtest.h>
#include <string>
#include "uci/uci.hpp"

using namespace std;

TEST(UciTest, UciCommand)
{ // uci followed by quit to exit the loop
    istringstream uci_command("uci\nquit\n");
    ostringstream uci_output;
    uci::start(uci_command, uci_output);
    auto uci_output_str = uci_output.str();
    EXPECT_NE(uci_output_str.find("id name toiletengine"), std::string::npos);
    EXPECT_NE(uci_output_str.find("id author"), std::string::npos);
    EXPECT_NE(uci_output_str.find("uciok"), std::string::npos);
}