// #include <bits/stdc++.h>
// using namespace std;
 
// #define endl "\n"
// #define int long long
// #define F first
// #define S second
// #define PB push_back
// #define MP make_pair
// #define us unordered_set
// #define REP(i, a, b) for (int i = a; i <= b; i++)

// typedef pair<int, int> p_int;

// int const MOD = 1e9 + 7;
// int const MAX_N = 1e12;

// template<class FWIt>
// void print_array(FWIt a, FWIt b) {
//   while (a != b) {
//     cout << *a << " ";
//     a++;
//   } cout << endl;
// }

// struct trie {
//   trie* bit[2];
// };

// trie* head;
 
// void run_case() {
//   int n;
//   cin >> n;

//   vector<int> a(n);
//   for (int i = 0; i < n; i++) {
//     cin >> a[i];
//   }

//   head = new trie();
//   trie* curr = head;
//   int const INT_SIZE = 30;
//   for (int i = INT_SIZE; i >= 0; i--) {
//     curr->bit[0] = new trie();
//     curr = curr->bit[0];
//   }

//   int pre_xor = 0;
//   int max_xor = 0;
//   for (int i = 0; i < n; i++) {
//     pre_xor ^= a[i];
//     curr = head;
//     // adding pre_xor to trie
//     for (int j = INT_SIZE; j >= 0; j--) {
//       int b = (1 << j) & pre_xor ? 1 : 0;
//       if (!curr->bit[b]) {
//         curr->bit[b] = new trie();
//       }
//       curr = curr->bit[b];
//     }

//     int curr_max = 0;
//     // max_xor = max(max_xor, a[i]);
//     curr = head;
//     for (int j = INT_SIZE; j >= 0; j--) {
//       int b = (1 << j) & pre_xor ? 1 : 0;
//       if (b) {
//         if (curr->bit[0]) {
//           curr_max |= (1 << j);
//           curr = curr->bit[0];
//         } else {
//           curr = curr->bit[1];
//         }
//       } else {
//         if (curr->bit[1]) {
//           curr_max |= (1 << j);
//           curr = curr->bit[1];
//         } else {
//           curr = curr->bit[0];
//         }
//       }
//       max_xor = max(max_xor, curr_max);
//     }
//   }

//   cout << max_xor << endl;

//   // cout << "Case #" << test_case << ": " << ans << endl;
// }
 
// int32_t main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   // freopen("test_input (3).txt", "r", stdin);
//   // freopen("maximum_xor_sum_output.txt", "w", stdout);
//   // int t;
//   // cin >> t;
//   // for (int i = 0; i < t; i++) {
//   //   run_case();
//   // }

//   run_case();
// }

// C++ program for a Trie based O(n) solution to find max
// subarray XOR
#include<bits/stdc++.h>
using namespace std;

// Assumed int size
#define INT_SIZE 40

// A Trie Node
struct TrieNode
{
	int value; // Only used in leaf nodes
	TrieNode *arr[2];
};

// Utility function to create a Trie node
TrieNode *newNode()
{
	TrieNode *temp = new TrieNode;
	temp->value = 0;
	temp->arr[0] = temp->arr[1] = NULL;
	return temp;
}

// Inserts pre_xor to trie with given root
void insert(TrieNode *root, int pre_xor)
{
	TrieNode *temp = root;

	// Start from the msb, insert all bits of
	// pre_xor into Trie
	for (int i=INT_SIZE-1; i>=0; i--)
	{
		// Find current bit in given prefix
		bool val = pre_xor & (1<<i);

		// Create a new node if needed
		if (temp->arr[val] == NULL)
			temp->arr[val] = newNode();

		temp = temp->arr[val];
	}

	// Store value at leaf node
	temp->value = pre_xor;
}

// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.
int query(TrieNode *root, int pre_xor)
{
	TrieNode *temp = root;
	for (int i=INT_SIZE-1; i>=0; i--)
	{
		// Find current bit in given prefix
		bool val = pre_xor & (1<<i);

		// Traverse Trie, first look for a
		// prefix that has opposite bit
		if (temp->arr[1-val]!=NULL)
			temp = temp->arr[1-val];

		// If there is no prefix with opposite
		// bit, then look for same bit.
		else if (temp->arr[val] != NULL)
			temp = temp->arr[val];
	}
	return pre_xor^(temp->value);
}

// Returns maximum XOR value of a subarray in arr[0..n-1]
int maxSubarrayXOR(int arr[], int n)
{
	// Create a Trie and insert 0 into it
	TrieNode *root = newNode();
	insert(root, 0);

	// Initialize answer and xor of current prefix
	int result = INT_MIN, pre_xor =0;

	// Traverse all input array element
	for (int i=0; i<n; i++)
	{
		// update current prefix xor and insert it into Trie
		pre_xor = pre_xor^arr[i];
		insert(root, pre_xor);

		// Query for current prefix xor in Trie and update
		// result if required
		result = max(result, query(root, pre_xor));
	}
	return result;
}

// Driver program to test above functions
int main()
{
  // freopen("test_input (3).txt", "r", stdin);
  // freopen("maximum_xor_sum_output.txt", "w", stdout);
  // cout << "hello" << endl;
  int n;
	cin >> n;
	int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

	cout << maxSubarrayXOR(arr, n);
	return 0;
}
