#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <algorithm>
using namespace std;

int main(){
	//Example writing
	string paragraph = "President Trump on Saturday once again attacked California during destructive wildfires, using erroneous claims. He said poor forest management policies caused the fires plaguing the state, even though the massive Woolsey fire didn’t occur in a forest. There is no reason for these massive, deadly and costly forest fires in California except that forest management is so poor. Billions of dollars are given each year, with so many lives lost, all because of gross mismanagement of the forests. Remedy now, or no more Fed payments! Trump wrote. The Woolsey fire started near Simi Valley in a hillside area next to the old Santa Susana Field Lab and quickly spread into nearby suburban communities. Some firefighters took to social media to point out the distinction. Mr. President, with all due respect, you are wrong. The fires in So. Cal are urban interface fires and have NOTHING to do with forest management. Come to SoCal and learn the facts & help the victims, the Pasadena Firefighters Assn. said on Twitter. Experts have also said forest management was not a factor in California’s two most destructive fires: the Camp, which burned more than 6,000 structures this week in Paradise, and the Tubbs fire last year in wine country. Forest thinning would not have stopped the Camp or the Tubbs. Fueled by dry grass growing amid scattered pine and oak trees, the Camp tore across land thinned by flames just 10 years ago. The Tubbs burned grassy oak woodlands, not timber land. Trump has threatened to cut off funding over fire policy before, but has never been specific. California officials have rejected his criticism and said he’s playing politics. Environmentalists believe Trump is trying to use fire prevention as an excuse to raid California’s forests. Some condemned Trump’s tweet. The president’s message attacking California and threatening to withhold aid to the victims of the cataclysmic fires is Ill-informed, ill-timed and demeaning to those who are suffering as well as the men and women on the front lines, California Professional Firefighter Assn. President Brian Rice said in a statement.";
	transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower); //change the writing to all lower-case
	
	
	string target;
	string replacement;
	int pid;
	
	cout << "Parent PID: " << getpid() << endl;
	cout << "----------------------------" << endl;
	
	//prompt for a target string
	//terminate the program if the input is "!wq"
	cout << "Target string: ";
	cin >> target;
	if(target == "!wq"){
		exit(0);
	}
	
	//prompt for a replacement string
	//terminate the program if the input is "!wq"
	cout << "Replacement string: ";
	cin >> replacement;
	if(replacement == "!wq"){
		exit(0);
	}
	cout << endl;
	
	//change both target and replacement words to lower-case
	transform(target.begin(), target.end(), target.begin(), ::tolower);
	transform(replacement.begin(), replacement.end(), replacement.begin(), ::tolower);
	
	while(true){
		//create a child process
		pid = fork();
		
		//for child process
		if(pid == 0){
			cout << "Child PID: " << getpid() << endl;
			//beginning point of replacement
			size_t start = 0;
			//counter of how many words are replaced
			int counter = 0;
			while(counter == 0){
				//while the target word is found
				while((start = paragraph.find(target, start)) != string::npos){
					//replace the target word with the replacement word
					paragraph.replace(start, target.length(), replacement);
					counter++;
					//increase the starting point of searching
					start += replacement.length();
				}
				//if the target word does not exist
				if(counter == 0){cout << "." << endl;}
				
				//print the number of words replaced
				cout << "Replaced words number: " << counter << endl;
				cout << "----------------------------"<<endl;
			}
			//exit the child process
			exit(0);
		}
		
		//for parent process
		else{
			//wait until the child process exits
			wait(NULL);
		}
		
		//prompt the user again
		//termiante the program when input is "!wq"
		cout << "Target string: ";
		cin >> target;
		if(target == "!wq"){
			exit(0);
		}
		
		cout << "Replacement string: ";
		cin >> replacement;
		if(replacement == "!wq"){
			exit(0);
		}
		cout << endl;
		
		//Change the inputs to lower-case
		transform(target.begin(), target.end(), target.begin(), ::tolower);
		transform(replacement.begin(), replacement.end(), replacement.begin(), ::tolower);
	
	}
			   


}
