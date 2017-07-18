class Solution {
public:
    string intToRoman(int num) {
        string nn = to_string(num);
		string mm = nn;
		for(int k = 0; k < mm.size(); k ++){
			mm[k] = nn[nn.size()-1 - k];
		}
		nn = mm;
		stack<string> ronum ;
        string res = "";
		for (int i = 0; i < nn.length(); i++  ){
			char c = nn[i];
			if(c >= '1' && c <= '3' ){
				if(i == 0){
						for(int j = 0; j < (c-48)%5 ; j++){
							ronum.push("I");
						}
				}
				else if(i == 1){
					for(int j = 0; j < (c-48)%5 ; j++){
							ronum.push("X");
						}
				}
				else if(i == 2){
					for(int j = 0; j < (c-48)%5 ; j++){
							ronum.push("C");
						}
				}
				else if(i == 3){
					for(int j = 0; j < (c-48)%5 ; j++){
							ronum.push("M");
						}
				}
				else {;}
			}
			else if(c == '4'){
				if(i == 0){
					ronum.push("V");
					ronum.push("I");
				}
				else if(i == 1){
					ronum.push("L");
					ronum.push("X");
				}
				else if(i == 2){
					ronum.push("D");
					ronum.push("C");
				}
				else {;}
			}
			else if ( c >= '6' && c <= '8'){
				if(i == 0){
					for(int j = 0; j < (c-48)%5 ; j++){
							ronum.push("I");
						}
					ronum.push("V");
				}
				else if(i == 1){
					for(int j = 0; j < (c-48)%5 ; j++){
							ronum.push("X");
						}
					ronum.push("L");
				}
				else if(i == 2){
					for(int j = 0; j < (c-48)%5 ; j++){
							ronum.push("C");
						}
					ronum.push("D");
				}
				else {;}
			}
			else if (c == '5'){
				if(i == 0){
					ronum.push("V");
				}
				else if(i == 1){
					ronum.push("L");
				}
				else if(i == 2){
					ronum.push("D");
				}
				else {;}
			}
			else if( c == '9'){
				if( i == 0){
					ronum.push("X");
					ronum.push("I");
				}
				else if(i == 1){
					ronum.push("C");
					ronum.push("X");
				}
				else if(i == 2){
					ronum.push("M");
					ronum.push("C");
				}
				else {;}
			}
			else{;}
		}
		while(!ronum.empty()){
			res += ronum.top();
			ronum.pop();
		}
        return res;
		
    }
};