class Solution {
public:
    bool isNumber(string s) {
        long long n = s.size();
        bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;

        for(int i = 0; i < n;i++){
            if(isdigit(s[i])) seenDigit = true;
            if((s[i] == '+' || s[i] == '-') && i > 0 && !seenExponent) return false;
            if((s[i] == '+' || s[i] == '-') && i > 0 && seenExponent && s[i-1] != 'e' && s[i-1] != 'E') return false;
            if(s[i] == '.' && (seenDot || seenExponent)) return false;
            else if(s[i] == '.' && !seenDot && !seenExponent) seenDot = true;
            if((s[i] == 'e' || s[i] == 'E') && (seenExponent || !seenDigit)) return false;
            else if((s[i] == 'e' || s[i] == 'E') && !seenExponent && seenDigit){
                seenExponent = true;
                seenDigit = false;
            }
            if(!isdigit(s[i]) && s[i] != 'e' && s[i] != 'E' && s[i] != '+' && s[i] != '-' && s[i] != '.') return false;
        }
        return seenDigit;
    }
};