#ifndef RPN_HPP
# define RPN_HPP

# include <stack>

typedef enum tokentype_e {
    OPERATOR,
    VALUE
} tokentype_t;

typedef struct token_s {
    tokentype_t type;
    char operation;
    unsigned int value;
} token_t;

class RPN {
public:
    RPN();
    RPN(const RPN &obj);
    ~RPN();
    RPN &operator=(const RPN &obj);

    std::stack<token_t> stack;
private:

};

#endif
