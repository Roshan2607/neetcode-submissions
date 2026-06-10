class Solution {
public:
    bool isValid(string s) {
       stack<char> brackets;
        
        for (char c : s)
        {
            if(c == '(' || c == '[' || c == '{')
            {
                brackets.push(c);
            }
            else
            {
                if(brackets.empty())
                {
                    return false;
                }

                char topElement = brackets.top();
                if ((c == ')' && topElement == '(') ||
                    (c == ']' && topElement == '[') ||
                    (c == '}' && topElement == '{')) 
                    {brackets.pop();}
                else
                {
                    return false;
                }
            }
        } 
        return brackets.empty();
    }
};
