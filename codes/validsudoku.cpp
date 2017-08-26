int Solution::isValidSudoku(const vector<string> &A) {
   int rwise[9][9]={0};
   int cwise[9][9]={0};
   int bwise[3][3][9]={0};
   for(int i=0;i<9;i++)
   {
       for(int j=0;j<9;j++)
       {
           if(A[i][j]!='.')
           {
               int x=A[i][j]-'1';
               if(rwise[i][x]++)
              return 0;
                if(cwise[x][j]++)
               return 0;
              
                if(bwise[i/3][j/3][x]++)
               return 0;
              
               
               
           }
           
           
       }
   }
   return 1;
    
}
