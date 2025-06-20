/* There is a constant time solution as well to this better than the binary
   search solution Approach: Since the walking is of the type
   [a,b,c,a,b,c,a,b,c] hence pattern is repeating So we can use the modulo
   operator to find the position of the current element in the pattern Time
   complexity: O(1) Space complexity: O(1)
*/

using namespace std;

int helper(int target, int a, int b, int c) {
  int cycle_time = a + b + c;
  int full_cycle = target / cycle_time;
  int total_time = full_cycle * cycle_time;
  int remaining_time = target % cycle_time;
  int count = 0;
  while (remaining_time > 0) {
    if (count == 0) {
      remaining_time -= a;
    } else if (count == 1) {
      remaining_time -= b;
    } else if (count == 2) {
      remaining_time -= c;
    }
    total_time++;
    count = (count + 1) % 3;
  }
  return total_time;
}
int main() {
  int a, b, c, n, test;
  for (int i = 0; i < test; i++) {
    std::cin >> target >> a >> b >> c;
    int ans = helper(n, a, b, c);
    std::cout << ans << endl;
  }
}

/* However there exist a binary search approach towards this where we get the
   intuition play on days for the days we can use the binary search to find the
   minimum number of days required to reach the target Time complexity:
   O(log(n)) Space complexity: O(1)
*/

using namespace std;

bool check(int target, int a, int b, int c, int days) {
  int fulldays = days / 3;
  int remaining_days = days % 3;
  int total_time = fulldays * (a + b + c);

  if (remaining_days >= 1)
    total_time += a;
  if (remaining_days >= 2)
    total_time += b;

  return total_time >= target;
}

int main() {
  int a, b, c, n, test;
  std::cin >> n >> a >> b >> c;
  for (int i = 0; i << test; i++) {
    int low = 0;
    int high = 1e9;
    int ans = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (check(n, a, b, c, mid)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    std::cout << ans << endl;
  }
}

/* Time complexity : O(log n)
   Space complexity : O(1)
*/
