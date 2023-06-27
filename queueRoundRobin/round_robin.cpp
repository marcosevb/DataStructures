#include<iostream>
#include<queue>
#include<fstream>
using namespace std;

class Process { //process class
private:

	int id; //all private variables
	int arrival_time;
	int time_needed;
	int finished_time = 0;

public:

	Process(int i, int a, int t) { //constructor
		id = i;
		arrival_time = a;
		time_needed = t;
	}

	int processTime() { //this will be what takes the value from needed time and adds it to finished time
		int temp = time_needed;

		if (time_needed <= 4) {
			time_needed = 0;
		}
		else {
			time_needed = time_needed - 4;
		}

		return temp;
	}

	void setFinishedTime(int time) { //setter for finished time
		finished_time = time;
	}

	int getArrivalTime() { //getter for arrival time
		return arrival_time;
	}

	int getTimeNeeded() { //getter for arrival time
		return time_needed;
	}

	void printInfo() { //prints the desired information in the correct format
		cout << "p" << id << " : finished at time " << finished_time << endl;
	}

};

int main() {

	vector<Process> allProcesses; // this vector is just to hold all processes we make
	queue<Process> processSchedule; //this queue will be use for the round robin part
	vector<Process> finishedOrder; //this vector will hold the correct order
	int temp1 = 0, temp2 = 0, temp3 = 0;

	ifstream myfile; //open up the file
	myfile.open("round_robin.txt");

	if (myfile.is_open()) {
		while (myfile >> temp1) { //read the file and use the values to initialize Process objects
			myfile >> temp2; //first value is ID, second is arrival time, third is time needed
			myfile >> temp3;
			Process tempProcess(temp1, temp2, temp3);
			allProcesses.push_back(tempProcess);
		}
	}
	else {
		cerr << "Could not open the file." << endl; //error message 
	}
	
	int finishingSize = allProcesses.size(); //this will be what checks if we have finshed all processes
	int currentTime = 0; //this will store the current time

	for (int i = 0; i < allProcesses.size(); i++) { //this will add any process with time zero
		if (currentTime >= allProcesses.at(i).getArrivalTime()) {
			processSchedule.push(allProcesses.at(i));
			allProcesses.erase(allProcesses.begin() + i);
		}
	}

	while (finishedOrder.size() != finishingSize) {

		if (!processSchedule.empty()) {
			int result = processSchedule.front().processTime(); //this runs the first process in the queue

			if (result <= 4) { //this is for when it is complete
				currentTime = currentTime + result;
				processSchedule.front().setFinishedTime(currentTime); //set the finished time
				finishedOrder.push_back(processSchedule.front()); //add to vector in order
				processSchedule.pop();
			}
			else {
				currentTime = currentTime + 4; //the process is not done do take it out of the queue
				Process temp = processSchedule.front();
				processSchedule.pop();
				for (int i = 0; i < allProcesses.size(); i++) { //check if any processes have arrived
					if (currentTime >= allProcesses.at(i).getArrivalTime()) {
						processSchedule.push(allProcesses.at(i));
						allProcesses.erase(allProcesses.begin() + i);
						i = i - 1;
					}
				}
				processSchedule.push(temp); //push incomplete process back into the queue
			}
		}

	}
	cout << "Round Robin Timing" << endl;
	for (int i = 0; i < finishedOrder.size(); i++) { //print the finished order
		finishedOrder.at(i).printInfo();
	}
}