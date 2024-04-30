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

    bool runInput(std::string const inputStr, std::string &errString);
    int32_t getResult() const;

private:
    std::stack<int32_t> _stack;
    bool _executeOperator(char o, std::string &errString);
};

#endif
