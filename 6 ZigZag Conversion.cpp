class Solution {
public:
    string convert(string s, int numRows) {
        //1,2 especial process
        if(s.length() <= numRows || numRows == 1){
            return s;
        }
        else if(numRows == 2){
            string sRes;
            sRes.resize(s.length());
            for(int i = 0 , k=0 ,flg = 0; i <= s.length()+1 ; i = i + 2,k++){
                if(flg == 1&&i >= s.length()){
                    break;
                    
                }
                if(i >= s.length()){
                    i = 1;
                    flg = 1;
                }
                sRes[k] = s[i];
            }
            return sRes;
        }
        else{
            //char array
            char arr[s.length()][numRows];
            for(int i = 0; i < s.length(); i++){
                for(int j = 0; j < numRows; j++){
                    arr[i][j] = '\0';
                }
            }
            //zigzag insert
            for(int k = 0, add = 0; k < s.length(); k++){
				//every full row makes a jump
                if((k+add)%numRows == 0 && k != 0){
                    add++;
                }
                if(((k+add)/numRows)%2 == 0){
                    arr[k][(k+add)%numRows] = s[k];
                }
                else if(((k+add)/numRows)%2 == 1){
                    arr[k][numRows-1 - (k+add)%numRows] = s[k];
                }
                
            }
            //new string
            string conv;
            conv.resize(s.length());
            int index = 0;
            for(int r = 0; r < numRows; r++){
                for(int n = 0; n < s.length(); n++){
                    if(arr[n][r] != '\0'){
                        conv[index] = arr[n][r];
                        index++;
                    }
                }
            }
            return conv;
    }
    }
};