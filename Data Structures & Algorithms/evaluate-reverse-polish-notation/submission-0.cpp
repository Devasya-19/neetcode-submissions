class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        int n=tokens.size();
        for(auto it : tokens){
            // string num1=st.top();
            // st.pop()
            // string num2=st.top();
            // st.pop();
            if(it=="+"){
                string num1=st.top();
                st.pop();
                string num2=st.top();
                st.pop();
                int n1=stoi(num1);
                int n2=stoi(num2);
                int s=n1+n2;
                string sum=to_string(s);
                st.push(sum);
            }
            else if(it=="-"){
                string num1=st.top();
                st.pop();
                string num2=st.top();
                st.pop();
                int n1=stoi(num1);
                int n2=stoi(num2);
                int d=n2-n1;
                string diff=to_string(d);
                st.push(diff);
            }
            else if(it=="*"){
                string num1=st.top();
                st.pop();
                string num2=st.top();
                st.pop();
                int n1=stoi(num1);
                int n2=stoi(num2);
                int p=n1*n2;
                string pro=to_string(p);
                st.push(pro);
            }
            else if(it=="/"){
                string num1=st.top();
                st.pop();
                string num2=st.top();
                st.pop();
                int n1=stoi(num1);
                int n2=stoi(num2);
                int di=n2/n1;
                string div=to_string(di);
                st.push(div);
            }
            else{
                st.push(it);
            }
        }
        int ans=stoi(st.top());
        return ans;
    }
};
