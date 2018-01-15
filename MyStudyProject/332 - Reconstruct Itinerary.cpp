//Given a list of airline tickets represented by pairs of departure and arrival airports[from, to], reconstruct the itinerary in order.All of the tickets belong to a man who departs from JFK.Thus, the itinerary must begin with JFK.
//Note:
//If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.For example, the itinerary["JFK", "LGA"] has a smaller lexical order than["JFK", "LGB"].
//All airports are represented by three capital letters(IATA code).
//You may assume all tickets form at least one valid itinerary.
//
//Example 1 :
//    tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//    Return["JFK", "MUC", "LHR", "SFO", "SJC"].
//    Example 2 :
//    tickets = [["JFK", "SFO"], ["JFK", "ATL"], ["SFO", "ATL"], ["ATL", "JFK"], ["ATL", "SFO"]]
//    Return["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"].
//    Another possible reconstruction is["JFK", "SFO", "ATL", "JFK", "ATL", "SFO"].But it is larger in lexical order.

#include "Header.h";
vector<string> Solution::findItinerary(vector<pair<string, string>> tickets) {
    map<string, multiset<string>> lines;
    
    for (pair<string, string> ticket : tickets) {
        lines[ticket.first].insert(ticket.second);
    }
    vector<string> ret;
    stack<string> st;
    string src = "JFK";
    st.push(src);
    while (!st.empty()) {
        string top = st.top();
        if (lines[top].empty()) {
            //https://leetcode.com/problems/reconstruct-itinerary/discuss/78832
            // If there is no more outgoing edges, append to itinerary
            // Two cases: 
            // 1. If it searchs the terminal end first, it will simply get
            //    added to the itinerary first as it should, and the proper route
            //    will still be traversed since its entry is still on the stack.
            // 2. If it search the proper route first, the dead end route will also
            //    get added to the itinerary first.

            ret.push_back(top);
            st.pop();
        }
        else {
            st.push(*lines[top].begin());
            lines[top].erase(lines[top].begin());
        }

    }
    reverse(ret.begin(), ret.end());
    return ret;
}
