class Solution {
public:
vector<string> temp_path;
vector<vector<string>> result_path;

void GeneratePath(unordered_map<string, unordered_set<string>> &path, const string &start, const string &end)
{
    temp_path.push_back(start);
    if(start == end)
    {
        vector<string> ret = temp_path;
        reverse(ret.begin(),ret.end());
        result_path.push_back(ret);
        return;
    }

    for(auto it = path[start].begin(); it != path[start].end(); ++it)
    {
            GeneratePath(path, *it, end);
            temp_path.pop_back();
    }
}
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{
    temp_path.clear();
    result_path.clear();

    unordered_set<string> current_step;
    unordered_set<string> next_step;

    unordered_map<string, unordered_set<string>> path;

    unordered_set<string> unvisited = dict;
    
    if(unvisited.count(start) > 0)
        unvisited.erase(start);
    
    current_step.insert(start);

    while( current_step.count(end) == 0 && unvisited.size() > 0 )
    {
        for(auto pcur = current_step.begin(); pcur != current_step.end(); ++pcur)
        {
            string word = *pcur;

            for(int i = 0; i < start.length(); ++i)
            {
                for(int j = 0; j < 26; j++)
                {
                    string tmp = word;
                    if( tmp[i] == 'a' + j )
                        continue;
                    tmp[i] = 'a' + j;
                    if( unvisited.count(tmp) > 0 )
                    {
                        next_step.insert(tmp);
                        path[tmp].insert(word);
                    }
                }
            }
        }

        if(next_step.empty()) break;
        for(auto it = next_step.begin() ; it != next_step.end(); ++it)
        {
            unvisited.erase(*it);
        }

        current_step = next_step;
        next_step.clear();
    }
    
    if(current_step.count(end) > 0)
        GeneratePath(path, end, start);

    return result_path;
}
};

class Solution {
public:
vector<vector<string>> output;
vector<string> cur;

void FindPath(unordered_map<string, unordered_set<string>> &graph, const string &start, const string &end)
{
    cur.push_back(start);
    if(start == end)
    {
        vector<string> ret = cur;
        reverse(ret.begin(),ret.end());
        output.push_back(ret);
        return;
    }

    for(auto it2 = graph[start].begin(); it2 != graph[start].end(); ++it2)
    {
            FindPath(graph, *it2, end);
            cur.pop_back();
    }
}


vector<vector<string>> findLadders(string start, string end, unordered_set<string> & _dict)
{
    unordered_set<string> dict = _dict;
    if(dict.count(start) >0)
        dict.erase(start);

    output.clear();
    cur.clear();
    
    unordered_map<string, unordered_set<string>> graph;
    queue<string> q;
    unordered_map<string, int> depth;
    
    q.push(start);
    depth[start] = 0;
    
    bool found = false;
    
    int cur_deep = 0;
    int pre_deep = 0;

    while(!q.empty())
    {

        string word = q.front();
        q.pop();
        
        pre_deep = cur_deep;
        cur_deep = depth[word];

        if(pre_deep != cur_deep)
        {
            if(depth.count(end) > 0)
            {
                found = true;
                break;
            }
            else if(depth.size() == dict.size() + 1)
                break;
        }


        for( int i = 0; i < start.length(); ++i)
        {
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                string tmp = word;
                if(tmp[i] != ch)
                {
                    tmp[i] = ch;
                    
                    int t = depth.count(tmp);
                    if((t == 0 && dict.count(tmp) > 0) || (t > 0 && depth[tmp] == cur_deep + 1) )
                    {
                             graph[tmp].insert(word);
                             if(t == 0)
                             {
                                q.push(tmp);
                                depth[tmp] = cur_deep + 1;
                             }
                    }
                }
            }
        }
    }

    if(found)
    {
        FindPath(graph, end, start);
    }

    return output;
}
};