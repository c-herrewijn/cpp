#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <cstdint>

class RPN {
public:
    RPN();
    RPN(const RPN &obj);
    ~RPN();
    RPN &operator=(const RPN &obj);

    void addNumberToStack(int32_t n);
    bool executeOperator(char o);
    bool verifyResult();
    int32_t getResult();

private:
    std::stack<int32_t> _stack;
};

#endif
