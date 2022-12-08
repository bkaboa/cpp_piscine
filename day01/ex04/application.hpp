#ifndef APPLICATION
# define APPLICATION

# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>

class Application
{
	private:
		std::string		fileName;
		std::string		oldString;
		std::string		newString;
		std::string		newFileName;

	public:
		Application(std::string, std::string, std::string);
		~Application();

		void		buidNewFile(void);
		std::string	get_fileName(void) const;
		void		replaceString(std::string &);
};

#endif
