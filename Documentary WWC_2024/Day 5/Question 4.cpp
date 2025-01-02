#include <string>
#include <stack>
#include <iostream>
using namespace std;
int main() {
    string s;
    cin>>s
    if (s.empty()) return true;
    if (s.size() % 2 == 1) return false;
    if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
    int e = s.size() - 1;
    if (s[e] == '(' || s[e] == '{' || s[e] == '[') return false;

    stack<char> st;
    st.push(s[0]);

    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        st.push(s[i]);
        continue;
      }
      if (st.empty()) return false;
      char c = st.top();
      st.pop();
      if (s[i] == ')' && c != '(') return false;
      if (s[i] == '}' && c != '{') return false;
      if (s[i] == ']' && c != '[') return false;
    }
    cout<<st.empty();
}
