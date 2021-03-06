//// 像剑指 Offer 里面一样无脑求全排列会无情的超时
//// 基本思路就是用一个一位数组标示排列
//// 其中数组下标表示行号，数组值表示列号，开始进行初始化保证不重复
//// 用额外两个数组表示主对角线以及副对角线
//// 利用同一主对角线行列差值相同和同一副对角线和值相同的特性
//// 需要注意的是，4*4 的棋盘有 7 条主对角线，而不是四条
//
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//
//class Solution {
//public:
//    /*
//     * @param n: The number of queens
//     * @return: All distinct solutions
//     */
//	int m_nCountOfLine;
//	void DFS(vector<vector<string>> &vecRet, vector<int> &vecNums, int nLevel
//		, vector<bool> &vecMajor, vector<bool> &vecMinor ){
//		if( nLevel == vecNums.size() ){
//			vector<string> vecTemp(vecNums.size(), string(vecNums.size(), '.'));
//			for( int i=0; i<vecNums.size(); i++ ){
//				vecTemp[i][vecNums[i]] = 'Q';
//			}
//			vecRet.push_back( vecTemp );
//			return;
//		}
//		for( int i=nLevel; i<vecNums.size(); i++ ){
//			swap( vecNums[nLevel], vecNums[i] );
//			int nRow = nLevel;
//			int nCol = vecNums[nLevel];
//
//			if( !vecMajor[ ( (nRow - nCol) + m_nCountOfLine ) % m_nCountOfLine ]
//				&& !vecMinor[ nRow + nCol ] ){
//				
//				vecMajor[ ( (nRow - nCol) + m_nCountOfLine ) % m_nCountOfLine ] = true;
//				vecMinor[ nRow + nCol ] = true;
//
//				DFS( vecRet, vecNums, nLevel+1, vecMajor, vecMinor );
//				
//				vecMajor[ ( (nRow - nCol) + m_nCountOfLine ) % m_nCountOfLine ] = false;
//				vecMinor[ nRow + nCol ] = false;
//			}
//			swap( vecNums[nLevel], vecNums[i] );
//		}
//	}
//
//    vector<vector<string>> solveNQueens(int n) {
//        // write your code here
//		vector<vector<string>> vecRet;
//		vector<int> vecNums;
//		m_nCountOfLine = n*2-1;
//		vector<bool> vecMajor( m_nCountOfLine, false );
//		vector<bool> vecMinor( m_nCountOfLine, false );
//
//		for( int i=0; i<n; i++ ){
//			vecNums.push_back(i);	
//		}
//		DFS( vecRet, vecNums, 0, vecMajor, vecMinor);
//		return vecRet; 
//    }
//};
//
//int main (){
//
//	Solution s;
//	s.solveNQueens( 8 );
//	return 0;
//}