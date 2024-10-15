inline bool isDigit(const char c) {
    return (c >= '0') && (c <= '9');
}
void parse_and_solve(const std::string& s1, const std::string& s2, std::ofstream& out) {
    const int S1 = s1.size();
    const int S2 = s2.size();
    if (S1 < S2) {
        parse_and_solve(s2, s1, out);
        return;
    }
    int cry = 0;
    int i = 0;
    int j = 0;
    while (i < S1 - 1) {
        while (i < S1 && (!isDigit(s1[i]))) { ++i; }
        while (j < S2 && (!isDigit(s2[j]))) { ++j; }
        const int n1 = s1[i] - '0';
        const int n2 = (j < S2) ? (s2[j] - '0') : 0;
        const int n = cry + n1 + n2;
        cry = n / 10;
        out << (n % 10);
        if (i < S1 - 2) {
            out << ",";
        }
        ++i;
        ++j;
    }
    if (cry > 0) {
        out << "," << cry;
    }
}
 static bool Solve = [](){
    std::ofstream out("user.out");
    std::string s1, s2;
    while (std::getline(std::cin, s1) && std::getline(std::cin, s2)) {
        out << "[";
        cout<<s1<<" "<<s2<<endl;
        parse_and_solve(s1, s2, out);
        out << "]\n";
    }
    out.flush();
    exit(0);
    return true;
}();

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int cry = 0;
            ListNode* res = new ListNode(-1);
            ListNode* tmp = res;

            while(!(l1 == nullptr && l2 == nullptr)) {
                int sumNode = 0;
                if(l1 && l2) {
                    sumNode = l1->val + l2->val + cry;
                    l1 = l1->next;
                    l2 = l2->next;
                }
                else if(l1) {
                    sumNode = l1->val + cry;
                    l1 = l1->next;
                }
                else {
                    sumNode = l2->val + cry;
                    l2 = l2->next;
                }
                ListNode* newNode = new ListNode(sumNode % 10);
                cry = sumNode > 9 ? 1 : 0;
                tmp->next = newNode;
                tmp = tmp->next;
            }
            
            if(cry == 1) {
                ListNode* newNode = new ListNode(1);
                tmp->next = newNode;
            }

            return res->next;
        }
};
