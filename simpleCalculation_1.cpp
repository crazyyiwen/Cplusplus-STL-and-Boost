inline size_t precedence(const char op)
{
    if (op == '+' || op =='-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op =='^')
        return 3;
    throw std:: runtime_error {string{"invalid operator: "} + op};
}
