//brute force --it dont work in case where input contains -1

// class Solution {
//     void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
//     // set all non-zero elements as -1 in the row i:
//     for (int j = 0; j < m; j++) {
         
//         if (matrix[i][j] != 0) {
//             matrix[i][j] = -1;
//         }
//     }
// }


// void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
//     // set all non-zero elements as -1 in the col j:
//     for (int i = 0; i < n; i++) {     
//         if (matrix[i][j] != 0) {
//             matrix[i][j] = -1;
//         }
//     }
// }

// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//          int n = matrix.size();
//          int m = matrix[0].size();
//     // Set -1 for rows and cols
//     // that contains 0. Don't mark any 0 as -1:
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == 0) {
//                 markRow(matrix, n, m, i);
//                 markCol(matrix, n, m, j);
//             }
//         }
//     }

//     // Finally, mark all -1 as 0:
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
           
//             if (matrix[i][j] == -1) {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
//     }
// };


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //better
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> row(n, 0); // row vector
        vector<int> col(m, 0); // col vector

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
    }
};