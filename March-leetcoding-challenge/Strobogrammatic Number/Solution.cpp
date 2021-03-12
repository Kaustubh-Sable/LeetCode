class Solution {
public:
    bool isCharInvalid(char ch) {
        if(ch=='2' || ch=='3'|| ch=='4'|| ch=='5'|| ch=='7')
            return true;
        return false;
    }
    
    bool isStrobogrammatic(string num) {
        int l = 0, r = num.size()-1;
        
        while(l<=r) {
            if(isCharInvalid(num[l]) || isCharInvalid(num[r])) {
                cout<<"1";
                return false;
            }
            if( (num[l]=='6' && num[r]!='9') || (num[l]=='9' && num[r]!='6') ) {
                cout<<"2";
                return false;
            }
            if(num[l]!='6' && num[l]!='9' && num[l]!=num[r]) {
                cout<<"3";
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
