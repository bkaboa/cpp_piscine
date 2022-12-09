#ifndef HARL
# define HARL

# include <string>
# include <iostream>

# define ERROR		"Harl eat the cat"
# define DEBUG		"need to hide the cat"
# define INFO		"Harl can't see the cat"
# define WARNING	"Harl can see the cat hide him quick"



class Harl
{
	public:
		Harl();
		~Harl();
		void complain( std::string level );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
