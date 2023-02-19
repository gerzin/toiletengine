#ifndef TOILETENGINE_UCI_HPP
#define TOILETENGINE_UCI_HPP

#include <iostream>

namespace uci
{
    /**
     * Start the UCI protocol.
     *
     * @param in input stream.
     * @param out output stream.
     */
    void start(std::istream &in, std::ostream &out = std::cout);
}
#endif