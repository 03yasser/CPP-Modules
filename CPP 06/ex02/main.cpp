#include "Base.h"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int num = rand();
	std::cout << "num: " << num << std::endl;
	
	if (num % 3 == 0)
		return (new A());
	else if (num % 3 == 1)
		return (new B());
	return (new C());
}

int main()
{
    Base* base = generate();
    
    std::cout << "Base: " << base << std::endl;
    
    A* a = dynamic_cast<A*>(base);
    if (a)
        std::cout << "A: " << a << std::endl;
    
    B* b = dynamic_cast<B*>(base);
    if (b)
        std::cout << "B: " << b << std::endl;
    
    C* c = dynamic_cast<C*>(base);
    if (c)
        std::cout << "C: " << c << std::endl;
    
    delete base;
    
    return (0);
    
}