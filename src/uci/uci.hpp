#ifndef TOILETENGINE_UCI_HPP
#define TOILETENGINE_UCI_HPP

#include <iostream>
/**
 * @brief Namespace containing the implementation of the Universal Chess Interface.
 */
namespace uci
{
    /**
     * @brief Start the UCI protocol.
     *
     * @param[in] in input stream.
     * @param[out] out output stream (default std::cout).
     */
    void start(std::istream &in, std::ostream &out = std::cout);

    class EngineOptions
    {
    public:
        EngineOptions();
        ~EngineOptions() = default;

    private:
    };

}
#endif