#ifndef CHECK
# define CHECK

# include "application.hpp"

class Check
{
	private:
		Application		&valour;

	public:
		Check(Application &);
		~Check();

		static void	checkArg(const int argc);
		void	checkFile(void) const;
};


#endif
