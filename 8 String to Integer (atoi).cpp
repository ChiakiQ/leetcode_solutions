class Solution {
public:
    int myAtoi(string str) {
		int result = 0;
		int flg = 0;
		bool blankFlg = true;
		auto temp = str.cbegin();
		//numbers of bits
		int nob = INT_MIN;
		//flag of bits + 1
		bool flgb = false;
		for(int i = 0; i < str.length(); i++){
		    if(*temp == ' ' && blankFlg == true){
		        temp ++;
		        continue;
		    }
		    //Positive and negative number judgment
		    if(blankFlg == true && *temp == '+'){
		        temp ++;
		        blankFlg = false;
		        continue;
		    }
		    if(blankFlg == true && *temp == '-'){
		        flg = 1;
		        blankFlg = false;
		        temp ++;
		        continue;
		    }
		    //when number
			if(*temp >=48 && *temp < 58){
			    blankFlg = false;
				result = result * 10 + ( *temp -48 );
			}
			else{
			    break;
			}
			
			temp ++;
			if( flgb == true ){
			    nob /= 10 ;
			}
			else {
			    flgb = true;
			}
		}
		result = flg ? -result : result;
		if ( ( !flg && result < 0 ) || ( !flg && nob == 0)){
		    result = INT_MAX;
		}
		else if ( ( flg && result > 0 ) || ( flg && nob == 0  )) {
		    result = INT_MIN;
		}
		return result;
    }
};