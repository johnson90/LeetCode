/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        
    if ( points.size() < 2)
        return points.size();
        
	int collineation_count = 2;
	
    bool flag = false;
    
	for(int i = 0; i < points.size(); ++i)
	{
	    int dup = 0;
		for(int j = i+1; j < points.size(); ++j)
		{

		    if( points[i].x == points[j].x && points[i].y == points[j].y )
		    {
		          dup++;
		          continue;
		    }
	        flag = true;	        
		    int count = 2 + dup;
			for(int k = j+1; k < points.size(); ++k)
			{
					int u_x = points[i].x - points[k].x;
					int u_y = points[i].y - points[k].y; 
					int v_x = points[j].x - points[k].x;
					int v_y = points[j].y - points[k].y; 
					if( v_x * u_y == v_y * u_x )
						count++;
			}
			if(count > collineation_count)
				collineation_count = count;
		}
	}
	
	if (!flag) return points.size();
	
	return collineation_count;        
    }
};