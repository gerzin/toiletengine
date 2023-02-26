#include "uci.hpp"
#include <string>

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
    bool done = false;
    std::string read_cmd;

    while (!done)
    {
        if (getline(in, read_cmd))
        {
            if (read_cmd == "uci")
            {
                id_reply(out);
                options_reply(out);
                uciok_reply(out);
            }

            else if (read_cmd == "quit")
            {
                done = true;
            }
        }
    }
}
