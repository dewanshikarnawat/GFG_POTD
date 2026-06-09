//Problem: Seating Arrangement
//Topic: Arrays + Greedy
//Pattern: Easy
//Language Used: C++(17)

class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        int n = seats.size();

        for (int i = 0; i < n - 1; i++) {
            if (seats[i] == 1 && seats[i + 1] == 1)
                return false;
        }

        int placed = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                bool leftEmpty = (i == 0 || seats[i - 1] == 0);
                bool rightEmpty = (i == n - 1 || seats[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    seats[i] = 1;  
                    placed++;

                    if (placed >= k)
                        return true;
                }
            }
        }

        return placed >= k;
        
    }
};
