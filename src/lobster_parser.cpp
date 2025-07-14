#include "lobster_parser.h"

LobsterParser::LobsterParser(const std::string& filename, char delimiter)
    : file_(filename), delimiter_(delimiter), line_(0) {
    if(!file_) {
        throw std::runtime_error("Failed to open file");
    }
}

bool LobsterParser::nextRow() {
    std::string line;
    if(!std::getline(file_, line)){
        return false;
    }

    current_row_.clear();
    std::stringstream ss(line);
    std::string cell;

    while(std::getline(ss, cell, delimiter_)) {
        current_row_.push_back(cell);
    }

    ++line_;
    return true;
}

std::vector<std::string> LobsterParser::getRow() const{
    return current_row_;
}

std::size_t LobsterParser::getLine() const {
    return line_;
}

void LobsterParser::reset() {
    file_.clear();
    file_.seekg(0);
    line_ = 0;
}

inline MessageType LobsterMessageParser::getType(int type) const {
    static constexpr std::array<MessageType, 8> lut = {
        MessageType::Unknown,
        MessageType::Submission,
        MessageType::Cancellation,
        MessageType::Deletion,
        MessageType::Visible_Execution,
        MessageType::Hidden_Execution,
        MessageType::Halt,
        MessageType::Unknown
    };
    return (type >= 1 && type <= 7) ? lut[type] : MessageType::Unknown;
}
