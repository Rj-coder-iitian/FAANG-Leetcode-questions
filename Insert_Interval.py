class Solution:
   
    def insert(self, intervals, newInterval):
        if len(intervals) == 0:     return [newInterval]   # Empty input
        
        begin, end = 0, len(intervals) - 1
        while begin <= end:
            mid = (begin + end) // 2
            if newInterval.start > intervals[mid].start:
                begin = mid + 1
            elif newInterval.start < intervals[mid].start:
                end = mid - 1
            else:
                begin = mid
                break
        # Insert the new interval into the old list.
        intervals = intervals[:begin] + [newInterval] + intervals[begin:]
        # Do merge if we could
        previous = Interval(intervals[0].start, intervals[0].end)
        result = []
        for interval in intervals[1:]:
            if interval.start > previous.end:
                # Cannot merge the current interval with the previous one
                result.append(previous)
                previous = Interval(interval.start, interval.end)
            else:
                # Merge the current interval with the previous one, by
                # extending the end position if possible
                previous.end = max(interval.end, previous.end)
        # Record the last one interval
        result.append(previous)
        return result
