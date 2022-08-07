class MyCalendar {
private:
    vector<pair<int, int> > status;
public:
    MyCalendar() {
        status = vector<pair<int, int> >();
        status.reserve(2000);
    }

    bool book(int start, int end) {
        bool checking = false;
        for (int i = 0; i < status.size(); i++) {
            pair<int, int> p = status[i];
            if (p.second == 1) {
                if (start <= p.first && p.first < end) {
                    return false;
                }
                if (p.first < start) {
                    checking = true;
                }
            }
            else {
                if (checking && start < p.first) {
                    return false;
                }
                checking = false;
            }
        }
        status.push_back(make_pair(start, 1));
        status.push_back(make_pair(end, -1));
        sort(status.begin(), status.end());
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
