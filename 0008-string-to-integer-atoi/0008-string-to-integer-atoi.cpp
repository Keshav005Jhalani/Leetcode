class Solution {
public:
    int myAtoi(string s) {
        int myNum=0;
        bool sign=true;
        int i=0;
        while(s[i]==' ') i++;
        if(s[i]=='-'||s[i]=='+'){
            sign=s[i]=='-'?false:true;
            i++;
        }
        while(s[i]<='9'&&s[i]>='0'){
            if((myNum > INT_MAX/10)||(myNum == INT_MAX/10 && s[i]>'7'))
                return sign?INT_MAX:INT_MIN; 
            myNum=myNum*10+(s[i]-'0');
            i++;
        }
        if(!sign) myNum*=-1;
        return myNum;
    }
};