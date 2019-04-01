#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void wallHeights(int numWalls, vector<int>& walls, string wallString){
	walls.resize(numWalls);

	istringstream  inWalls (wallString);

	for(int i = 0; i < walls.size(); i++){
		inWalls >> walls.at(i);
	}
}
void totalJumps(int T, vector<int>& walls, int numWalls, int& lowJumps, int& hiJumps){
	for(int i = 0; i < T; i++){

		string wallString;
		getline(cin, wallString);
		wallHeights(numWalls, walls, wallString);
		for(int k = 0; k < walls.size() - 1; k++){
			if(walls.at(k) < walls.at(k+1)){
				hiJumps++;
			}
			else if(walls.at(k) > walls.at(k+1)){
				lowJumps++;
			}
		}
	}
}
int main() {
	vector<int> walls;
	int T, numWalls;
	int hiJumps = 0;
	int lowJumps = 0;
	string wallString;
	do {
		cin >> T;
	}while(T < 0 || T > 30);
	do{
		cin >> numWalls;
	}while(numWalls < 0 || numWalls > 50);
	getline(cin, wallString);
	for(int i = 0; i < T; i++) {
		totalJumps(T, walls, numWalls, lowJumps, hiJumps);
		cout << "Case " << i << ": " << hiJumps << " " << lowJumps << endl;
	}
	return 0;
}

