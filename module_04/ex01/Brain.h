#ifndef BRAIN_H
# define BRAIN_H
# include <string>

class Brain {
public:
    Brain();
    Brain(const Brain &obj);
    ~Brain();
    Brain &operator=(const Brain &obj);

    void brainDump(void) const;
    std::string ideas[100];
};

#endif
