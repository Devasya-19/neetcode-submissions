class Solution {
public:
    void f(string& digits,int i,vector<string>&freq,
    vector<string>&ans,string& words){
        if(i==digits.size()){
            ans.push_back(words);
            return ;
        }
        string letters=freq[digits[i]-'0'];
        for(auto ch:letters){
            words.push_back(ch);
            f(digits,i+1,freq,ans,words);
            words.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string>freq(10,"");
        char c='a';
        for(int i=2;i<10;i++){
            if(i==9 || i==7){
                freq[i]+=c;
                c++;
                freq[i]+=c;
                c++;
                freq[i]+=c;
                c++;
                freq[i]+=c;
                c++;
            }
            else{
                freq[i]+=c;
                c++;
                freq[i]+=c;
                c++;
                freq[i]+=c;
                c++;
            }
        }
        vector<string>ans;
        string words="";
        f(digits,0,freq,ans,words);
        return ans;
    }
};
