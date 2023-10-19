#include <string>

class Harl {
public:
    void complain(std::string complainLevelStr) const;

private:
    void debug(void) const;
    void info(void) const;
    void warning(void) const;
    void error(void) const;
    int getComplainLevelInt(std::string ComplainLevelStr) const;

    typedef struct s_complainMap {
        std::string level;
        void (Harl::*complainFunction)(void) const;
    } t_complainMap;
    static t_complainMap complainMap[];
};
