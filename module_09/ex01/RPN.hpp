#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <cstdint>
# include <string>

class RPN {
public:
    RPN();
    RPN(const RPN &obj);
    ~RPN();
    RPN &operator=(const RPN &obj);

    bool runInput(std::string);
    int32_t getResult();

private:
    bool _executeOperator(char o);
    std::stack<int32_t> _stack;
};

#endif
