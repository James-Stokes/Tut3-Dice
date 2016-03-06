#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Dice {
private:
	int rollResults[10];

public:

	Dice() {
		srand(time(NULL));
	}

	~Dice() {

	}
	int roll() {
		
		return rand() % 6 + 1;
	}

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

	float average(int arr[], int num) {
		int average = 0;
		for (int i = 0; i < num; i++) {
			average += arr[i];
			cout << arr[i] << endl;
		}
		return average / num;
	}

	int* getRollResults() {
		return rollResults;
	}

	void setRollResults(int num) {
		for (int i = 0; i < num; i++) {
				this->rollResults[i] = this->roll();
		}
	}
};

int main() {
	Dice dice;
	while (true) {
		int choice;
		cout << "do you want to do dice(1) or arrays(2) or EXIT(3)?" << endl;
		cin >> choice;
			switch (choice)
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