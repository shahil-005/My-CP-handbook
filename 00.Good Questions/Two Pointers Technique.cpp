//https://www.geeksforgeeks.org/two-pointers-technique/

//O(n^2)
// Naive solution to find if there is a 
// pair in A[0..N-1] with given sum. 
bool isPairSum(A[], N, X) 
{ 
	for (i = 0; i < N; i++) { 
		for (j = 0; j < N; j++) { 
			if (A[i] + A[j] == X) 
				return true; // pair exists 

			if (A[i] + A[j] > X) 
				break; // as the array is sorted 
		} 
	} 

	// No pair found with given sum. 
	return false; 
} 


O(n)
// Two pointer technique based solution to find 
// if there is a pair in A[0..N-1] with a given sum. 
bool isPairSum(A[], N, X) 
{ 
	// represents first pointer 
	int i = 0; 

	// represents second pointer 
	int j = N - 1; 

	while (i < j) { 

		// If we find a pair 
		if (A[i] + A[j] == X) 
			return true; 

		// If sum of elements at current 
		// pointers is less, we move towards 
		// higher values by doing i++ 
		else if (A[i] + A[j] < X) 
			i++; 

		// If sum of elements at current 
		// pointers is more, we move towards 
		// lower values by doing j-- 
		else
			j--; 
	} 
	return false; 
} 
