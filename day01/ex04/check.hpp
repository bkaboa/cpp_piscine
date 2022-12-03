#ifndef CHECK
# define CHECK

# include "application.hpp"

class Check
{
	public:
		Check();
		~Check();

		static void	checkArg(const int argc, const char **argv);
		static void	checkFile(const char *fileName);
};


#endif
