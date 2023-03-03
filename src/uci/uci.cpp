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

    void help_reply(std::ostream &out)
    {
        out << "The help for toiletengine hasn't been written yet." << std::endl;
    }
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
            for (auto token = tok.begin(); token != tok.end(); ++token)
            {
                if (*token == "uci")
                {
                    id_reply(out);
                    options_reply(out);
                    uciok_reply(out);
                    break;
                }

                else if (*token == "quit" || *token == "exit")
                {
                    done = true;
                    break;
                }

                else if (*token == "debug")
                {
                    auto option = token;
                    for (++option; option != tok.end(); ++option)
                    {
                        if (*option == "on")
                        {
                            out << "found debug on" << std::endl;
                            break;
                        }
                        else if (*option == "off")
                        {
                            out << "found debug off" << std::endl;
                            break;
                        }
                    }
                }
                else if (*token == "isready")
                {
                    out << "readyok" << std::endl;
                    break;
                }
                else if (*token == "help")
                {
                    help_reply(out);
                    break;
                }
                else if (*token == "setoption")
                {
                    if (++token != tok.end() && *token == "name")
                    {
                        if (++token != tok.end())
                        {
                            std::string name = *token;
                            if (++token != tok.end() && *token == "value")
                            {

                                if (++token != tok.end())
                                {
                                    std::string value;
                                    value = *token;
                                    out << "NAME: " << name << " VALUE: " << value << std::endl;
                                    break;
                                }
                                else
                                    break;
                            }
                            out << "NAME: " << name << std::endl;
                            break;
                        }
                        else
                            break;
                    }
                    else
                    {
                        out << "Unknown command: " << read_cmd << std::endl;
                        break;
                    }
                }
                else
                {
                    out << "Unknown command: " << read_cmd << std::endl;
                    break;
                }
            }
        }
    }
}

std::ostream &operator<<(std::ostream &out, const uci::EngineOptions &e)
{
    return out;
}
