class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Refer Abhyuday Dixit for most optimised approach
        
        int rows = matrix.size(), cols = matrix[0].size();
        
        bool fisrtRowhasZeroes = false;
        
        for(int i=0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) fisrtRowhasZeroes = true;
                    else matrix[i][0] = 0;
                
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = rows - 1; i >= 0; i--){
            for(int j = cols - 1; j >= 0; j--){
                if(i == 0 and fisrtRowhasZeroes) matrix[i][j] =0;
                else if(i != 0 and (matrix[i][0] == 0 || matrix[0][j] == 0)) matrix[i][j] = 0;
            }
        }
       
    }
};