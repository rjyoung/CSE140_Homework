#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

vector<int> decToBinary(int num, int numRows) {
    vector<int> binary;
    int paramNum = num;
    int power = log2(numRows);
    int temp = (power - 1);
    
    while(temp >= 0 ) {
        if(num >= exp2(temp)) {
            binary.push_back(1);
            num -= exp2(temp);
            temp--;
        }
        else {
            binary.push_back(0);
            temp--;
        }
    }
    while( binary.size() < log2(numRows)) {
        binary.insert(binary.begin(), 0);
    }
    return binary;
    
}

vector<int> countToBinary(vector<int> b, int num) {
    int sum = 0;
    for( int bit : b){
        if(bit)
            sum++;
    }
    
    vector<int> countB; 
    int power = log2(num);
    int temp = (power - 1);
    
    while(temp >= 0 ) {
        if(sum >= exp2(temp)) {
            countB.push_back(1);
            sum -= exp2(temp);
            temp--;
        }
        else {
            countB.push_back(0);
            temp--;
        }
    }
     while( countB.size() < log2(num)) {
        countB.insert(countB.begin(), 0);
    }
  //  int y2 = sum >= 4 ? 1 : 0;
//    int y1 = (sum - 4) >= 2 ? 1 : 0;
  //  int y0 = (sum - 5) >= 0 ? 1 : 0;
    
    return countB;
}


int main()
{
    printf("id |a5 | a4 | a3 | a2 | a1 | a0 | y2 | y1 | y0\n");
    printf("----------------------------------------------\n");
    for(int i = 0; i < 64; i++) {
        vector<int> d = decToBinary(i, 64);
        vector<int> out = countToBinary(d, 8);
        printf("%2d & %2d & %2d & %2d & %2d & %2d & %2d & %2d & %2d & %2d\\\\\n", 
        i, d.at(0), d.at(1), d.at(2), d.at(3), d.at(4), d.at(5), out.at(0), out.at(1), out.at(2));
        
    }
    
    return 0;
}