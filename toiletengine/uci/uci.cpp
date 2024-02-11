export module uci;
/**
 * @brief Universal Chess Interface implementation.
 *
 */
namespace uci {
/**
 * @brief Commands that the GUI can send to the engine.
 *
 */
enum GuiCommand : unsigned char {
  Uci = 0,
  Debug,
  Isready,
  Setoption,
  Position,
  Go,
  Stop,
  Ponderhit,
  Quit,
  // Unofficial supported commands
  Help
};

}  // namespace uci
