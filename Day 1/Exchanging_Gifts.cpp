//Problem Statement
// The royal family exchanges gifts at Christmas, where the youngest member receives gifts from everyone but doesn't give any gifts. Given the data for all the exchanged gifts among the family members, you need to identify the youngest member, who is the one receiving gifts from everyone but not giving any.

// Note: A family member does not give more than one gift to the same member.

// Input Format
// The first line of the input contains two integers n and m denoting the number of family members and the number of gifts that were exchanged.
// The next m lines contain two integers each. In the ith line, two integers ai, bi represent that a gift was given by ai to bi.

// Output Format
// Print a single integer, the number that represents the youngest member of the family.
// If no such member is found, print “-1” instead.

// Constraints
// 1 <= n <= 104
// 0 <= m <= 105
// 1 <= ai, bi, <= n

#include <iostream>
#include <vector>

void find_youngest_member(int n, int m, std::vector<std::pair<int, int>> &gifts) {

    std::vector<int> given(n+1,0);
    std::vector<int> received(n+1,0);
    int ans=-1;

    for(int i=0; i<m ; i++){
        given[gifts[i].first]++;
        received[gifts[i].second]++;
    }

    for(int i=1; i<=n ; i++){
        if ((received[i]==n-1)&&(given[i]==0)) ans=i;
        else continue;
    }

    std::cout<<ans;


}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> gifts(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> gifts[i].first >> gifts[i].second;
    }
    find_youngest_member(n, m, gifts);
    return 0;
}
