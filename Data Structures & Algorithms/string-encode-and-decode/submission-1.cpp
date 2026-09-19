class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded_string="";
        int i=0;
        for(auto it : strs ){
            int n=it.size();
            string size=to_string(n);
            size+='#';
            encoded_string+=size;
            encoded_string+=it;
        }
        // cout<<encoded_string;
        return encoded_string;
        
    }

    vector<string> decode(string s) {
        vector<string>ans;
        string word="";
        int i=0;
        while(i<s.size()){
            int subsize=0;
            while(s[i]!='#'){
                subsize=subsize*10+(s[i]-'0');
                i++;
            }
            i++;
            ans.push_back(s.substr(i,subsize));
            i+=subsize;
        }
        return ans;
    }
};
