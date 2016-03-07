/*
James Stokes
UKZN
Tut3-Dice, Computer methods 3
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Dice {
private:
	int rollResults[10]; //stores all the results of rolls made by the roll method

public:

	Dice() {
		srand(time(NULL)); //create random seed using the time class
	}

	~Dice() {

	}

	//roll a random number from 1 to 6 for a die roll
	int roll() {
		return rand() % 6 + 1;
	}

	//calculates the average of dice rolls 
	float average(Dice d, int num) {
		int average = 0;
		int* resultsArray = d.getRollResults();
		for (int i = 0; i < num; i++) {
			cout << *resultsArray << endl; 
			average += *resultsArray;
			resultsArray++;
		}
		return average / num;
	}

	//calculates the average of an array of ints
	float average(int arr[], int num) {
		int average = 0;
		for (int i = 0; i < num; i++) {
			average += arr[i];
			cout << arr[i] << endl;
		}
		return average / num;
	}

	//returns a pointer to the rollResults array
	int* getRollResults() {
		return rollResults;
	}

	//calls the roll method to popualte the rollResults array
	void setRollResults(int num) {
		for (int i = 0; i < num; i++) {
				rollResults[i] = roll();
		}
	}
};

int main() {
	Dice dice;
	while (true) { //while loop to run the menu
		int choice;
		cout << "do you want to do dice(1) or arrays(2) or EXIT(3)?" << endl;
		cin >> choice;
			switch (choice) //allows the user to choose an operation or to exit
			{
			case 1:
				int numOfTimes;
				cout << "how many times do you want to roll the dice (max 10)?" << endl;
				cin >> numOfTimes;
				if (numOfTimes > 10) {
					cout << "thats too many, defaulting to 10" << endl;
					numOfTimes = 10;
				}
				cout << "\n" << endl;
				dice.setRollResults(numOfTimes);
				cout << "the average is: " << dice.average(dice, numOfTimes) << endl;
				break;
			case 2:
				int numOfNumbers;
				cout << "how long do you want the array to be (max 10)?" << endl;
				cin >> numOfNumbers;
				if (numOfNumbers > 10) {
					cout << "thats too many, defaulting to 10" << endl;
					numOfNumbers = 10;
				}
				cout << "\n" << endl;
				int nums[10];
				for (int i = 0; i < numOfNumbers; i++) {
					nums[i] = dice.roll();
				}
				cout << "the average is: " << dice.average(nums, numOfNumbers) << endl;
				break;
			case 3:
				return 0;
			default:
				cout << "INVALID" << endl;
				break;
			}
		}
	return 0;
}