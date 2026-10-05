# Segment Tree
## How to identify that the question is of Segment Tree

1. You have an array and many queries
2. The array changes during queries
3. Contraints are large (Brute force solution taking O(N) per query)
--> segment tree usually gives query in O(log(N)) and update O(log(N))
4. The query asked for the operations that can be combined for example: sum(1,8): sum(1,4)+sum(5,8)

**NOTE: Some keywords that strongly indicates that the problem is of segment tree -:**
- Range query
- Subarray query
- Interval query
- Online queries
- Point update
- Range update
- Dynamic updates

## Queries 
1. Partial Overlap of node with range [l,r] --> return (leftNode, rightNode)
2. No Overlap with range [l,r] --> return INT_MAX
3. Complete Overlap with [l,r] --> return segmentTree[ind]