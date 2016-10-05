#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class CLI{
	public:
		CLI();
		~CLI();

		int readAllConfigFiles();

		int readConfigFile();
		int readConfigFile(string);
		int readLicenseFile();
		int readLicenseFile(string);
		int readHelpFile();
		int readHelpFile(string);
		int readGreetingFile();
		int readGreetingFile(string);

		int addArgument(string);
                int addConfig(string);

		void greeter();
		void license();
		void help();

		bool filesLoaded();
		bool noArguments();

		string getConfigValue(int);
		string getArgumentValue(int);
	private:
		vector<string> argumentValues;

		vector<string> configValues;

		string licenseData, helpData, greetingData;
};
