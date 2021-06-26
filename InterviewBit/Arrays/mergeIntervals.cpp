#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compareInterval(Interval i1, Interval i2){
    return i1.start<i2.start;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    newInterval.start = min(newInterval.start,newInterval.end);
    newInterval.end = max(newInterval.start,newInterval.end);
    intervals.push_back(newInterval);
    int n = intervals.size();
    if(n == 1) return intervals;
    sort(intervals.begin(),intervals.end(),compareInterval);
    int index = 0;
    for(int i=1;i<n;i++){
        if(intervals[index].end>=intervals[i].start){
            intervals[index].end = max(intervals[index].end,intervals[i].end);
            intervals[index].start = min(intervals[index].start,intervals[i].end);
        }else{
            index++;
            intervals[index] = intervals[i];
        }
    }
    intervals.erase(intervals.begin()+index+1,intervals.end());
    return intervals;
}