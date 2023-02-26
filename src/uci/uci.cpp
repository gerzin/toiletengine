#include "uci.hpp"
#include <string>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

namespace
{
    inline void id_reply(std::ostream &out)
    {
        out << "id name toiletengine 0.0" << std::endl;
        out << "id author Gerardo Zinno & co. (see CONTRIBUTORS file)" << std::endl;
    }

    inline void options_reply(std::ostream &out)
    {
    }

    inline void uciok_reply(std::ostream &out) { out << "uciok" << std::endl; }
}

void uci::start(std::istream &in, std::ostream &out)
{
    boost::char_separator<char> sep(" ", "\t");
    using Tokenizer = boost::tokenizer<decltype(sep)>;

    std::string read_cmd;
    bool done = false;
    while (!done)
    {
        if (getline(in, read_cmd))
        {
            boost::trim(read_cmd);
            Tokenizer tok(read_cmd, sep);
            for (const auto &token : tok)
            {
                if (token == "uci")
                {
                    id_reply(out);
                    options_reply(out);
                    uciok_reply(out);
                    break;
                }

                else if (read_cmd == "quit")
                {
                    done = true;
                    break;
                }
            }
        }
    }
}
