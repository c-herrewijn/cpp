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
    void updateBrain(size_t index, std::string idea);
    std::string ideas[100];
};

#endif
