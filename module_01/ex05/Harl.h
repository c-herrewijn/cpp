#include <string>

class Harl {

public:
    void complain(std::string level);

private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    typedef struct s_complainMap {
        std::string level;
        void (Harl::*complainFunction)(void);
    } t_complainMap;
    static t_complainMap complainMap[];
};
