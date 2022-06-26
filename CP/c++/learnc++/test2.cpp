#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(2);
    pq.push(3);
    cout<<pq.top();
    pq.remove(3);
    pq.top();
}
