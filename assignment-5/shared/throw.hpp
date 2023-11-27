#ifndef THROW_HPP
#define THROW_HPP

void __throw_if_min1(int x, const char* file, unsigned int line, const char* message = nullptr);

#define throw_if_min1(___x___)					__throw_if_min1((___x___), __FILE__, __LINE__)
#define throw_if_min1_msg(___x___, ___msg___)	__throw_if_min1((___x___), __FILE__, __LINE__, ___msg___)

#endif // THROW_HPP
