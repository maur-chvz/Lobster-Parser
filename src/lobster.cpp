#include "lobster_parser.h"

int main() {
    LobsterMessageParser message("../test/AAPL_2012-06-21_34200000_57600000_message_1.csv");
    LobsterOrderbookParser orderbook("../test/AAPL_2012-06-21_34200000_57600000_orderbook_1.csv");
    // message.nextRow();
    // std::vector<std::string> x = message.getRow();
    // for(auto const& i : x) {std::cout << i << '\n';}

    orderbook.nextRow();
    std::vector<std::string> x = orderbook.getRow();
    for(auto const& i : x) {std::cout << i << '\n';}
    return 0;
}