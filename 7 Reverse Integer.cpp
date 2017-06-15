class Solution {
public:
    int reverse(int x) {
        char temp[10] = "";
		bool flg = x > 0 ? 0 : 1;
		for(int i = 0; x != 0; i++){
		    int t = flg ? -( x % 10 ) : x % 10;
			temp[i] = t + 48;
			x = x/10;
		}
		string str = temp;
		int result = 0;
		try{
		    result = stoi(str);
		}catch(std::out_of_range msg){
		    return 0;
		}
		if(flg){
			result = -result;
		}
		if(flg && result > 0){
			result = 0;
		}
		return result;
    }
};