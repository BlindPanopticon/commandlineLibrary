#include "CLI.h"

int main(int argc, char *argv[]){
	CLI program;
	
	cout << program.readAllConfigFiles() << endl;
	
	if(!program.filesLoaded()){
		program.help();
		return -1;
	}

	cout << program.getConfigValue(0) << endl;
	program.greeter();
	program.help();
	program.license();

	for(int x = 0; x < argc; ++x){
		program.addArgument(argv[x]);
		cout << program.getArgumentValue(x) << endl;
	}

	if(program.noArguments()){
		program.help();
		return -1;
	}

	return 0;
}
