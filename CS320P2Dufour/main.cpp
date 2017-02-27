#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int generateSet(vector<int> &v, int t);
void sortSet(vector<int> &v);
void printSubSet(vector<int> v);
void findSubSets(vector<int> s, vector<int> ss, int sS, int ssS, int cS, int cNC, int t);
int main(){
	int total = 0;
	cout << "Please enter a total sum to find: ";
	cin >> total;

	vector<int> numSet{ 1,2,3,4,5,6,7,8 };
	vector<int> subSet(numSet.size());
	//int sizeOfSet = generateSet(numSet, total);
	int sizeOfSet = 8;
	sortSet(numSet);
	findSubSets(numSet, subSet, sizeOfSet, 0, 0, 0, total);
    return 0;
}

int generateSet(vector<int> &v, int total) {
	int totalEntered = 0;
	cout << "Please enter numbers for a set: ";
	int tempValue;
	for (int i = 0; i < total; i++) {
		cin >> tempValue;
		v.push_back(tempValue);
		totalEntered++;
	}
	return totalEntered;
}

void sortSet(vector<int> &v){

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
	printSubSet(v);
}
/*
vector<vector<int>> calculateSubSets(vector<int> const &v, int total){
    
    vector<vector<int>> subSets;
    int totalSubsets = 0;
    vector<int> workingVector = v;

    //checks to see if the last element is already equal to the total
    if(workingVector.back() == total){
        vector<int> subSet;
        subSet.push_back(workingVector.back());
        subSets.push_back(subSet);
        workingVector.erase(workingVector.end()-1);
        totalSubsets++;
    }

    //While the size of the vector is greater than 0
    while(workingVector.size() > 0){
		vector<int> subSet;
		vector<int> markedNumbers;
		int currentTotal = 0;
		int curValue = workingVector.back();
		int nextValue = workingVector.at(workingVector.size() - 2);
		for (int i = workingVector.size() - 3; i >= 0; i--) {
			if (curValue + nextValue == total) {
				subSet.push_back(nextValue);
				subSet.push_back(curValue);
				subSets.push_back(subSet);
				markedNumbers.push_back(nextValue);
				break;
			}
			else if (curValue + workingVector.at(i) == total) {
				subSet.push_back(i);
				subSet.push_back(nextValue);
				subSet.push_back(curValue);
				markedNumbers.push_back(nextValue);
				markedNumbers.push_back(workingVector.at(i));
				subSets.push_back(subSet);
				if (i == 0) {
					workingVector.erase(workingVector.end()-1);

				}
				break;
			}
		}
    }
    
    cout << "Total subSets that equal total: " << totalSubsets << endl;
    return subSets;
}
*/

//Recsurively
void findSubSets(vector<int> set, vector<int> subSet, int setSize, int subSetSize, int curSum, int curNodeCount, int total) {
	if (curSum == total) {
		printSubSet(subSet);
		findSubSets(set, subSet, setSize, subSetSize - 1, curSum - set[curNodeCount], curNodeCount++, total);
		return;
	}
	else {
		if (curNodeCount < setSize && curSum + set[curNodeCount] < total) {
			for (int i = curNodeCount; i < setSize; i++) {
				subSet[subSetSize] = set[i];
				if (curSum + set[i] <= total) {
					findSubSets(set, subSet, setSize, subSetSize + 1, curSum + set[i], i + 1, total);
				}
			}
		}
	}
}

void printSubSet(vector<int> subSet) {
	cout << "{ ";
	for (int i = 0; i < subSet.size(); i++) {
		cout << subSet[i] << ", ";
	}
	cout << " }" << endl;
}