// Ashurov, Anvar
// CS211 52A Homework 4 

#include <iostream>
using namespace std;

bool invalid(int arr[], string input) {
	bool isInvalid = true;
	int value = 0;
	    if(input.size() <= 1) return isInvalid;
	    for (int i = 0; i < 26; i++) {
		    if (arr[i] != 0) {
			    value = arr[i]; //store the first nonzero element (later to compare to other non-zero values.)
			    break; //only here for 1 non-zero value.
		    }
	    }
	    for (int j = 0; j < 26; j++) { //this whole loop checks if other non-zero elements is equal to the first non-zero element. (If not, then we have a team with more/less members)
		    if (arr[j] != 0) {
			    if (arr[j] == value) isInvalid = false;
			    else isInvalid = true;
		    }
	    }
	return isInvalid;
}
int result(int arr[], string input) {
	int teams = 0;
	int runners = 0;
	    for (int i = 0; i < 26; i++) {
		    if (arr[i] > 0) { //This counts number of teams.
			    teams++;
			    runners = arr[i]; //Since we are in result() because invalid() returned false, hence, any value of arr[i]>0 presents us the number of runners on each team. 
		    }
	    }
	    cout << endl << "There is/are " << teams << " team(s)." << endl;
	    cout << "There is/are " << runners << " runner(s) on each team." << endl << endl;
	int index, secondarr[26] = {0}; //secondarr[] will store the sum of indices of each team (same technique as storing number of runners on each team.)
	    for (int j = 0; j < 26; j++) {
	   	    index = input[j] - 'A'; //0; 1;
		    secondarr[index] = secondarr[index] + j+1; //number of repetitions;
	    }  
	double winnerScore[26] = {0};
	double winnerTeam[26] = {0};
    	cout << "Team   Score" << endl; 
    	for (int q = 0; q < 26; q++) {
	        if(arr[q] > 0 && secondarr[q] > 0) {
	            cout << "   " << (char)('A' + q) << "   " << (double)secondarr[q]/arr[q] << " points." << endl;
	            winnerScore[q] = (double)secondarr[q]/arr[q];
	            winnerTeam[q] = (double)secondarr[q]/arr[q];
	        }
	    }
	double min, firstscore;
	    for(int r = 0; r < 26; r++) {
	        if (winnerScore[r] != 0) {
	    		firstscore = winnerScore[r]; //store the first nonzero element (later to compare to other non-zero values.)
    			break; //only here for 1 non-zero value.
	    	}
	    }
	min = firstscore; 
	string win; //stores the winning team.
        for(int s = 1; s < 26; s++) { //sorting to get smallest score.
            if(winnerScore[s] != 0) {
	            if(winnerScore[s] < min) min = winnerScore[s];
	         }
        }
        for(int t = 0; t < 26; t++) { //Getting the letter of the winner.
            if(winnerTeam[t] == min) win = (char)(t+'A'); 
        }
    	cout << endl << "Team " << win << " won the race with "<< min << " points." << endl;
}
int main() {
	string input;
	bool ans = true;
	int difference, size, inputArray[26] = { 0 };
        while(ans == true) {
         	for(int i = 0; i < 26; i++) inputArray[i] = {0};
    	        cout << "Enter your race: ";
                cin >> input;
    	        size = input.size();
    	    for (int i = 0; i < size; i++) {
	        	difference = input[i] - 'A'; //0; 1; (Numer of runners)
	        	inputArray[difference] = inputArray[difference] + 1; //Elements in the array are number of runners on each team. 
	        }
        	if (invalid(inputArray, input)) { 
        	    ans = true;
        	}
	        else {
	            ans = false;
	            result(inputArray, input);
	        }
        }
    return 0; 
}
