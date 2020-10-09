class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        auto pt = head;
        unordered_set<ListNode*> s;
        while(s.find(pt) == s.end())
        {
            s.insert(pt);
            pt = pt->next;
            if(!pt)
                return false;
        }
        return true;
    }
};