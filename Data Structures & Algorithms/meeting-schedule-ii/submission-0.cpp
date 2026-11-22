/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
        //     return a.start < b.start;
        // });
        int n = intervals.size();
        int rooms = 0;
        vector<int> start;
        vector<int> end;
        
        for(const auto& interval : intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        //int currtime = 0;
        int s = 0, e = 0;
        int count = 0;
        while(s<n){
            
            if(start[s]<end[e]){
                count++;
                s++;
            }
            else{
                count--;
                e++;
            }
            rooms = max(rooms, count);
        }
        return rooms;
    }
};
