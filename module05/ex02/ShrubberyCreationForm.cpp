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
	if (this == &sForm)
		return *this;
	this->target = sForm.target;
	this->setIsSigned(sForm.getIsSigned());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	ShrubberyCreationForm::execute(Bureaucrat const	&executer) {
	std::ofstream	outfile;
	std::string		filename = target;

	filename.append("_shrubbery");

	outfile.open(filename); // 아웃파일 열기 실패시 예외처리 필요
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