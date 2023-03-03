#ifndef TOILETENGINE_UCI_HPP
#define TOILETENGINE_UCI_HPP
#include <map>

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

    /**
     * @brief Options of the engine.
     */
    class EngineOptions
    {
    public:
        EngineOptions();
        ~EngineOptions() = default;

        /**
         * @brief write the options on the output stream.
         *
         * Write all the options on the output stream in the UCI compliant form
         * ```
         * option name <name> <value> ...
         * ```
         * @param[out] out output stream on which to write the options.
         * @param[in] e EngineOption object containing the options to write.
         */
        friend std::ostream &operator<<(std::ostream &out, const EngineOptions &e);

    private:
        std::map<std::string, std::string> optionMap;
    };

}
#endif