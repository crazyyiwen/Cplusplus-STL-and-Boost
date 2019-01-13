double execute(std::stack<char>& ops, std::stack<double>& operands)
{
    double result {};
    double rhs {operands.top()};                            // Get rhs...
    operands.pop();                                         // ...and delete from stack
    double lhs {operands.top()};                            // Get lhs...
    operands.pop();                                         // ...and delete from stack

    switch (ops.top())                                      // Execute current op
    {
        case '+':
            result = lhs + rhs;
            break;
        case '-':
            result = lhs - rhs;
            break;
        case '*':
            result = lhs * rhs;
            break;
        case '/':
            result = lhs / rhs;
            break;
        case '^':
            result = std::pow(lhs, rhs);
            break;
        default:
            throw std::runtime_error {string{"invalid operator: "} + ops.top()};
    }
    ops.pop(); // Delete op just executed
    operands.push(result);
    return result;
}
