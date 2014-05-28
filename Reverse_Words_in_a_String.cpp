class Solution {
public:
    void reverseWords(string &s) {
		if (s.empty())
			return;

		int h = 0;
		for(; h < s.length() && s[h] == ' '; h++) {}
		
		if ( h == s.length())
		{
			s = "";
			return;
		}

		int i, j;
		for ( i = 0; s[i] == ' '; i++){}
		for ( j = s.length()-1; s[j] == ' ' ; j--) {}

		int new_len = j - i + 1;
		char * temp = new char[new_len+1];
		char * reverse = new char[new_len+1];

		for(int k = i, t = 0; k <= j; k++)
		{
			temp[t++] = s[k];
		}

		i = j = new_len - 1;
		
		int p = 0;
		
		while( i >= 0 )
		{
			while( i >= 0 && temp[i] != ' ') i--;
			if( i< 0) break;
			strncpy(reverse+p, temp+i+1, j - i);
			p += (j-i);
			reverse[p] = ' ';
			p++;
			while( temp[i] == ' ') i--;
			j = i;
		}

		strncpy(reverse + p, temp, j+1);

		reverse[p + j + 1] = '\0';
		s.assign(reverse);

		delete []temp;
		delete []reverse;     
    }
};