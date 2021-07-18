/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool mycomp(Interval &a, Interval &b)
{
    return a.start < b.start;
}
void MergeIntervals(vector<Interval> &intervals, vector<Interval> &res)
{
    //sort on start time
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), mycomp);
    int start = intervals[0].start;
    int end = intervals[0].end;
    for (int i = 1; i < n; i++)
    {
        if (end < intervals[i].start)
        {
            res.push_back(Interval(start, end));
            //update start and end
            start = intervals[i].start;
            end = intervals[i].end;
        }
        else
        {
            start = min(start, intervals[i].start);
            end = max(end, intervals[i].end);
        }
    }
    res.push_back(Interval(start, end));
    return;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    /*
    int start = newInterval.start;
    int end = newInterval.end;
    vector<Interval> res;
    // I need to get the interval index in which start and end will there
    //lowerbound of start
    int n = intervals.size();
    int ind1 = -1;
    for(int i=0; i<n; i++){
        if(start<=intervals[i].end){
            ind1= i;
            break;
        }
    }
    if(ind1 == -1){
        //insert at last;
        intervals.push_back(newInterval);
        return intervals;
    }
    int ind2 = -1;
    for(int i=n-1; i>=0; i--){
        if(end>=intervals[i].start){
            ind2 = i;
            break;
        }
    }
    if(ind2 == -1){
        //create new interval
        intervals.insert(intervals.begin(),Interval(start,end));
        return intervals;
    }
    for(int i=0; i<ind1; i++){
        res.push_back(intervals[i]);
    }
   
    //merge intevals in between [ind1,ind2] or create one
    // cout<<"ind1 "<<ind1<<"ind2 "<<ind2<<"\n";
    if(ind1>ind2){
        //new interval
        res.push_back(Interval(start,end));
    }
    else{
        start = min(start,intervals[ind1].start);//merge
        end = max(end,intervals[ind2].end);//merge
        Interval In = Interval(start,end);
        res.push_back(In);
    }    
    for(int i=ind2+1; i<n; i++){
        res.push_back(intervals[i]);
    }
    return res;
    */
    intervals.push_back(newInterval);
    vector<Interval> res;
    MergeIntervals(intervals, res);
    return res;
}
