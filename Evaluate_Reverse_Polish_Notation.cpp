class Solution {
public:
    int evalRPN(vector<string> &tokens) {
	stack<int> s;
	int op1, op2, tmp;
	for(int i = 0; i < tokens.size(); i++)
	{
		if( tokens[i] == "+" )
		{
			op2 = s.top();
			s.pop();
			op1 = s.top();
			s.pop();
			tmp = op1 + op2;
			s.push(tmp);
		}
		else if(tokens[i] == "-")
		{
			op2 = s.top();
			s.pop();
			op1 = s.top();
			s.pop();
			tmp = op1 - op2;
			s.push(tmp);
		}
		else if(tokens[i] == "*")
		{
			op2 = s.top();
			s.pop();
			op1 = s.top();
			s.pop();
			tmp = op1 * op2;
			s.push(tmp);
		}	
		else if(tokens[i] == "/")
		{
			op2 = s.top();
			s.pop();
			op1 = s.top();
			s.pop();
			tmp = op1 / op2;
			s.push(tmp);
		}
		else
		{
			s.push(atoi(tokens[i].c_str()));
		}
	}
	return s.top();        
    }
};