#include "CLI.h"

#define FILE_CONFIG	"CONF/CONFIG"
#define FILE_LICENSE	"CONF/LICENSE"
#define FILE_HELP 	"CONF/HELP"
#define FILE_GREETING	"CONF/GREETING"

CLI::CLI(){}
CLI::~CLI(){
	argumentValues.clear();
	configValues.clear();
}

int CLI::readAllConfigFiles(){
	int tmp = 0;

	tmp += readConfigFile();
	tmp += readLicenseFile();
	tmp += readHelpFile();
	tmp += readGreetingFile();

	return tmp;
}

int CLI::readConfigFile(){
	return readConfigFile(FILE_CONFIG);
}
int CLI::readConfigFile(string file){
	ifstream File(file.c_str());
	
	if(File.is_open()){
		string tmp;

		while(File.good()){
			getline(File,tmp);
			configValues.push_back(tmp);
		}
		return configValues.size();
	}
	return -1;
}

int CLI::readLicenseFile(){
	return readLicenseFile(FILE_LICENSE);	
}
int CLI::readLicenseFile(string file){
	ifstream File(file.c_str());

        if(File.is_open()){
                string tmp;

                while(File.good()){
                        getline(File,tmp);
                        licenseData += tmp + "\n";
                }
		return licenseData.size(); 
        }
	return -1;
}

int CLI::readHelpFile(){
	return readHelpFile(FILE_HELP);
}
int CLI::readHelpFile(string file){
	ifstream File(file.c_str());

        if(File.is_open()){
                string tmp;

                while(File.good()){
                        getline(File,tmp);
                        helpData += tmp + "\n";
                }
                return helpData.size();
        }
        return -1;
}


int CLI::readGreetingFile(){
	return readGreetingFile(FILE_GREETING);
}
int CLI::readGreetingFile(string file){
	ifstream File(file.c_str());

        if(File.is_open()){
                string tmp;

                while(File.good()){
                        getline(File,tmp);
                        greetingData += tmp + "\n";
                }
                return greetingData.size();
        }
        return -1;
}


int CLI::addArgument(string argument){
	argumentValues.push_back(argument);
	return argumentValues.size();
}
int CLI::addConfig(string config){
	configValues.push_back(config);
	return configValues.size();
}

void CLI::greeter(){
	if(!greetingData.empty()){
		cout << greetingData;
	}else{
		cout << "\nGreeting file has not been read\n";
	}
}
void CLI::license(){
        if(!licenseData.empty()){
                cout << licenseData;
        }else{
                cout << "\nLicense file has not been read\n";
        }
}
void CLI::help(){
        if(!helpData.empty()){
                cout << helpData;
        }else{
                cout << "\nHelp file has not been read\n";
        }
}

bool CLI::filesLoaded(){
	return !configValues.empty() & !licenseData.empty() & !helpData.empty() & !greetingData.empty();
}
bool CLI::noArguments(){
	return argumentValues.empty();
}

string CLI::getConfigValue(int pointer){
	return configValues[pointer];
}

string CLI::getArgumentValue(int pointer){
	return argumentValues[pointer];
}
