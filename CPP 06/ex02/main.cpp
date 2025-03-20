#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base*	generate(void)
{
	int num = std::rand(); 
	// std::cout << "num: " << num % 3 << std::endl;
	
	if (num % 3 == 0)
		return (new A());
	else if (num % 3 == 1)
		return (new B());
	return (new C());
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Unknown type" << std::endl;
}


int main()
{
	std::srand(time(0)); 
    Base* base = generate();
    
    identify(base);
	identify(*base);
    
    delete base;
    
    return (0);
    
}