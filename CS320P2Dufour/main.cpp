#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


void generateSet(vector<int> &v);
void sortSet(vector<int> &v);
vector<vector<int>> calculateSubSets(vector<int> &v, int total);
void printSubSet(vector<vector<int>> &v);
vector<int> searchSubSets(vector<int> &ss, int n, int wt);

int main(){

    vector<int> numSet;



    return 0;
}

void generateSet(vector<int> &v){

}

void sortSet(vector<int> &v){

    sort(v.being(), v.end());
    v.erase(unique(v.begin, v.end), v.end);

}

vector<vector<int>> calculateSubSets(vector<int> const &v, int total){
    
    vector<vector<int>> subSets;
    int totalSubsets = 0;
    vector<int> workingVector = v;
    //checks to see if the last element is already equal to the total
    if(workingVector.back() == total){
        vector<int> subSet;
        subSet.push_back(workingVector.back());
        subSets.push_back(subSet);
        workingVector.erase(workingVector.end());
        totalSubsets++;
    }

    //While the size of the vector is greater than 0
    while(workingVector.size() > 0){
        //create a new subvector
        vector<int> subVec = workingVector;
        //remove the last element of the subvector so workingVector.back() is not it
        subVec.remove(subVec.back());
        //
        while(subVec.size() > 0){
            vector<int> subSet;
            subSet.push_back(workingVector.back());
            int currentTotal = workingVector.back();
            for(int j = subVec.size() - 2; j >= 0; j++){
                if(currentTotal + subVec.at(j) <= total){
                    subSet.push_back(subVec.at(j));
                    currentTotal += subVec.at(j);
                    searchSubSets(subVec, j, currentTotal);
                }
            }
        }
    }
    
    cout << "Total subSets that equal total: " << totalSubsets << endl;
    return subSets;
}

vector<int> searchSubSets(vector<int> &subVec, int currentValue, int workingTotal){
    for(int k = currentValue - 1; k >= 0; k++){
        if(currentTotal + subVec.at(k) <= total){
            subSet.push_back(subVec.at(k));
            currentTotal += subVec.at(k);
        }
    }
}