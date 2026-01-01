class RecentCounter {
    queue<int> q;

public:
    RecentCounter() {
    }

    int ping(int t) {
        // add current ping
        q.push(t);

        // remove old pings
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        // remaining pings count
        return q.size();
    }
};
