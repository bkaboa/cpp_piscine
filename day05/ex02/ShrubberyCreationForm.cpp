#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 137, 145) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):AForm("ShrubberyCreationForm", 137, 145), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm(other.getName(), other.getExecGrade(), other.getSignGrade()){
	this->target = other.getTarget();
	*this = other;
}

const ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->setIsSigned(other.getSign());
		this->setTarget(other.getTarget());
	}
	return (*this);
}

void createFilePutTreeIn(std::string target)
{
	std::ofstream	out(target.append("_shrubbery").c_str());
	std::string		tree="                                                      .\n                                              .         ;  \n                 .              .              ;%     ;;   \n                   ,           ,                :;%  %;   \n                    :         ;                   :;%;'     .,   \n           ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'   \n                        `@%.  `;@%.      ;@@%;         \n                          `@%%. `@%%    ;@@%;        \n                            ;@%. :@%%  %@@%;       \n                              %@bd%%%bd%%:;     \n                                #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '         \n                                %@@@o%;:(.,'         \n                            `.. %@@@o%::;         \n                               `)@@@o%::;         \n                                %@@(o)::;        \n                               .%@@@@%::;         \n                               ;%@@@@%::;.          \n                              ;%@@@@%%:;;;. \n                          ...;%@@@@@%%:;;;;,..    Gilo97";
	out << tree << std::endl;
}

bool	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSign())
		throw FormNotSigned();
	else if (this->getExecGrade() < executor.getGrade())
		throw GradeTooHightExceptionExecution();
	else
	{
		createFilePutTreeIn(this->getTarget());
		return (true);
	}
	return (false);
}

const std::string	&ShrubberyCreationForm::getTarget(void) const {
	return (target);
}

void	ShrubberyCreationForm::setTarget(const std::string &target){
	this->target = target;
}
