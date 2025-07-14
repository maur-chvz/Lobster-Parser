#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <array>

enum class MessageType {
    Submission,
    Cancellation,
    Deletion,
    Visible_Execution,
    Hidden_Execution,
    Halt,
    Unknown = 0
};


class LobsterParser {
public:
    virtual ~LobsterParser() = default;
    bool nextRow();
    std::vector<std::string> getRow() const;
    std::size_t getLine() const;
    void reset();
protected:
    LobsterParser(const std::string& filename, char delimiter = ',');
    std::ifstream file_;
    std::vector<std::string> current_row_;
    char delimiter_;
    std::size_t line_ = 0;
};

class LobsterMessageParser : public LobsterParser {
public:
    LobsterMessageParser(const std::string& filename, char delimiter = ',')
        : LobsterParser(filename, delimiter) {}

    MessageType getType(int x) const;
private:
    std::uint64_t time_;
    MessageType type_;
};

class LobsterOrderbookParser : public LobsterParser {
public:
    LobsterOrderbookParser(const std::string& filename, char delimiter = ',')
        : LobsterParser(filename, delimiter) {}
private:
    
};