#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) {
	target = "none";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string	target) : Form("ShrubberyCreationForm", 145, 137) {
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm	&sForm) : Form("ShrubberyCreationForm", 145, 137) {
	this->target = sForm.target;
	this->setIsSigned(sForm.getIsSigned());
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm	&sForm) {
	if (this == &sForm
		|| getToSign() != sForm.getToSign()
		|| getToExecute() != sForm.getToExecute()
		|| getName() != sForm.getName())
		return *this;
	target = sForm.target;
	setIsSigned(sForm.getIsSigned());
	return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	ShrubberyCreationForm::execute(Bureaucrat const	&executer) const {
	std::ofstream	outfile;
	std::string		filename = target;

	if (!getIsSigned())
		throw FormNotSigned();
	this->isHigher(getToExecute(), executer.getGrade());

	filename.append("_shrubbery");

	outfile.open(filename);
	if (outfile.fail())
		throw OpenFailed();
	outfile << "                     ; ; ;\n";
	outfile << "                    ;        ;  ;     ;;    ;" << std::endl;
	outfile << "                 ;                 ;         ;  ;" << std::endl;
	outfile << "                                 ;" << std::endl;
	outfile << "                                ;                ;;" << std::endl;
	outfile << "                ;          ;            ;              ;" << std::endl;
	outfile << "                ;            ';,        ;               ;" << std::endl;
	outfile << "                ;              'b      *" << std::endl;
	outfile << "                 ;              '$    ;;                ;;" << std::endl;
	outfile << "                ;    ;           $:   ;:               ;" << std::endl;
	outfile << "              ;;      ;  ;;      *;  @):        ;   ; ;" << std::endl;
	outfile << "                           ;     :@,@):   ,;**:'   ;" << std::endl;
	outfile << "               ;      ;,         :@@*: ;;**'      ;   ;" << std::endl;
	outfile << "                        ';o;    ;:(@';@*\"'  ;" << std::endl;
	outfile << "                ;  ;       'bq,;;:,@@*'   ,*      ;  ;" << std::endl;
	outfile << "                           ,p$q8,:@)'  ;p*'      ;" << std::endl;
	outfile << "                    ;     '  ; '@@Pp@@*'    ;  ;" << std::endl;
	outfile << "                     ;  ; ;;    Y7'.'     ;  ;" << std::endl;
	outfile << "                               :@):." << std::endl;
	outfile << "                              .:@:'." << std::endl;
	outfile << "                            .::(@:.      -Sam Blumenstein-" << std::endl;

	outfile.close();
}

ShrubberyCreationForm	*ShrubberyCreationForm::getNewForm(std::string	target) {
	return new ShrubberyCreationForm(target);
}