#include <iostream>
#include <string>
#include<vector>
using std::string;
using std::min;
using std::vector;
int edit_distance(const string &str1, const string &str2) {
	int n=str1.length();
	int m=str2.length();
	vector<vector<int>> D;
	D.resize(n+1,vector<int>(m+1,0));
    for (int i=0;i<=n;i++){
		D[i][0]=i;
	}
	for (int j=0;j<=m;j++){
		D[0][j]=j;
	}
	int miss=0;
	int min1,min2;
	for (int j=1;j<=m;j++){
		for (int i=1;i<=n;i++){
			min1=min(D[i-1][j]+1,D[i][j-1]+1);
			
			if (str1[i-1]==str2[j-1]){
				miss=0;
			}
			else{
				miss=1;
			}
			min2=min(min1,D[i-1][j-1]+miss);
			D[i][j]=min2;
			
			//std::cout<<D[i][j]<<std::endl;
		}
	}
  return D[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
