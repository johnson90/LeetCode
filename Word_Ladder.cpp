class Solution {
public:
int ladderLength(string start, string end, unordered_set<string> &dict) 
{
	queue<string> q;
	q.push(start);
	q.push(" ");
	dict.insert(start);
	int count = 1;
	unordered_set<string> flag;
	flag.insert(start);

	while( count <= dict.size())
	{
		string e = q.front();
		q.pop();
		if(e != " ")
		{
			for(int i = 0; i < e.length(); i++)
			{
				for(int j = 0; j < 26; j++)
				{
					string tmp = e;
					if(tmp[i] != char('a' + j))
					{
						tmp[i] = char('a' + j);
						if(tmp == end)
							return count+1;
						else if(dict.count(tmp) > 0 && flag.count(tmp) == 0)
						{	
							q.push(tmp);
							flag.insert(tmp);
						}
					}
				}
			}
		}
		else if(e == " ")
		{
			q.push(" ");
			count++;
		}
	}
	return 0;
}
};