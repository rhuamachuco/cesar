#include <string>
#include <iostream>

//prototypes
char encrypt(char, int); //the method that will encrypt the original value of each char
char decipher(char, int); //the method that will decrypt the message

int main()
{
	//este es el main del programa donde todo se ejecuta
	std::string answer;
	std::string input;
	std::string output = "";
	int shift;

	std::cout << "Do you want to encrypt or decrypt a string? \n";
	getline(std::cin, answer);
	if (answer == "decrypt") {
		std::cout << "Enter the code to decipher \n";
		getline(std::cin, input);
		std::cout << "Enter the number you think the code is shifted by: ";
		std::cin >> shift;
		for (int i = 0; i < input.length(); i++)
		{
			output += decipher(input[i], shift); //calls the decipher method for each char in input and puts the return value in input
		}

		std::cout << output << "\n";
	}
	else if (answer == "encrypt") {
		std::cout << "Enter a string to encrypt. \n";
		getline(std::cin, input);
		std::cout << "Enter a number to shift by: ";
		std::cin >> shift;
		for (int i = 0; i < input.length(); i++)
		{
			output += encrypt(input[i], shift); //calls the encrypt method for each char in input and puts the return value in input
		}

		std::cout << output << "\n";
	}



	return 0;
}
/*end main*/

//method for encrypting the string
char encrypt(char letter, int shift) {
	int rotNum = shift;
	if (isalpha(letter)) { //checks to make sure that we are encrypting the letter
		letter = tolower(letter);  //makes the letter lowercase
		letter = (((letter - 97) + rotNum) % 26) + 97; //performs the shift according to the ASCII table
		if (!islower(letter)){  //if the letter is shifted in to an uppercase letter, make it lowercase
			letter = (((letter - 97) + (rotNum / 2)) % 26) + 97;
		}
		letter = tolower(letter);
	}

	return letter;
}

//funciton for decrypting a string. So far it works for decrypting strings that are shifted up to 17 spaces by the encrypt function
char decipher(char letter, int shift) {
	int rotNum = shift;

	if (isalpha(letter)) {
		letter = tolower(letter);
		letter = (((letter - 97) - rotNum) % 26) + 97;
		if (!islower(letter) && rotNum < 7){
			letter = (((letter - 97) - (rotNum / 2)) % 26) + 97;
		}
		else if (!islower(letter) && rotNum > 6) {
			letter = ((((letter - 97) - (rotNum)) % 26) + 97) + (rotNum-6);
		}
		letter = tolower(letter);
	}
	return letter;
}
