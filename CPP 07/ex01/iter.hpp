#ifndef ITER_HPP
# define ITER_HPP

class iter
{
	public :
		iter(void);
		iter(iter const &copy);
		~iter(void);
		iter& operator=(const iter &other);
};

#endif