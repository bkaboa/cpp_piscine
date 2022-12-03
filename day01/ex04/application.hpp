#ifndef APPLICATION
# define APPLICATION

# include <string>
# include <iostream>
#include <fstream>

class Application
{
	private:
		std::string		oldString;
		std::string		newString;
		std::string		fileName;
		std::string		newFileName;

	public:
		Application(std::string, std::string, std::string);
		~Application();

		void		buidNewFile(void);
		std::string	get_fileName(void) const;
		void	replaceString(std::string &);
};

#endif
