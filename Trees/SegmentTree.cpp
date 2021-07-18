vector<int> tree = vector<int> (2*n);
void build(int node,int start,int end,vector<int> &A){
    if(start == end){
        //this step varies generally
        tree[node] = A[start];
    }
    else{
        int mid = start+(end-start)/2;
        //left child at 2*node
        build(2*node,start,mid,A);
        //right child at 2*node+1
        build(2*node+1,mid+1,A);
        //union/summation of both halves
        tree[node] = tree[2*node]+tree[2*node+1];
    }
}
void update(int node,int start,int end,int idx,int val,vector<int> &A){
    if(start == end){
        //this step differs for RMQ
        A[idx] += val;
        tree[node] += val;
    }
    else{
        int mid = start+(end-start) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}