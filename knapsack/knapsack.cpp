#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int Weight, const vector<int> &w) {
	int length=w.size();
	//initialize 2D Array
	vector<vector<int>> value;
	value.resize(length+1,vector<int>(Weight+1,0));
	for (int i=0;i<=length;i++){
		value[i][0]=0;
	}
	for (int j=0;j<=Weight;j++){
		value[0][j]=0;
	}
	for (int i=1;i<=length;i++){
		for(int j=1;j<=Weight;j++){
			value[i][j]=value[i-1][j];
			if(w[i-1]<=j){
				int wi=w[i-1];
				int val=value[i-1][j-wi]+wi;
				if(value[i][j]<val) {
					value[i][j]=val;
				}
			}
		}
	}
	
	return value[length][Weight];
 }

int main() {
  int n, W;
  
   std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
