#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class freqFile {
	private:
		string filePath_;
		int freqAlphabet[26];
	public:
		freqFile(string filePath) {
			memset(freqAlphabet, 0, sizeof(freqAlphabet));
			filePath_ = filePath;
		}

		void readFile() {
			ifstream in;
			string str;

			in.open(filePath_);

			while (getline(in, str)) {
				for (int i = 0; i < str.length(); i++) {
					if ('a' <= str[i] && str[i] <= 'z') {
						freqAlphabet[str[i] - 'a'] += 1;
					} else if ('A' <= str[i] && str[i] <= 'Z') { 
						freqAlphabet[str[i] - 'A'] += 1;
					}
				}
			}

		    in.close();
		}

		void showFreq() {
			for (int i = 0; i < 26; i++) {
				printf("[%c] = %d\n", 'a' + i, freqAlphabet[i]);
			}
		}
};

int main(int argc, char const *argv[])
{
	freqFile myFile("main.cpp");
	myFile.readFile();
	myFile.showFreq();
	return 0;
}