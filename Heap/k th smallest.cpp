int kthSmallest(int arr[], int l, int n, int k) {
    //code here
    priority_queue<int>pq;
    for(int i=l;i<=n;i++)
    {
        pq.push(arr[i]);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    return pq.top();
}
