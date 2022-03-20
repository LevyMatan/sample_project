
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    // int count_set_bit_single(int num)
    // {
    //     int count = 0;
    //     for(unsigned int bit_idx = 0; bit_idx < 32; bit_idx++)
    //     {
    //         if((1U << bit_idx) & num)
    //         {
    //             count++;
    //         }
    //     }
        
    //     return count;
    // }
    
    int find_left_most_bit_idx(int num)
    {
        // std::cout << std::bitset<32>(num) << std::endl;
        for(unsigned int bit_idx = 31; bit_idx > 0; bit_idx--)
        {
            if((1U << bit_idx) & num)
            {
                return bit_idx;
            }
        }
        
        return 0;
    }
    
    int countSetBits(int n)
    {
        int total_of_bits_set = 0;
        int bits_in_last_num = 0;
        while(n)
        {
            // std::cout << "=======================================" << std::endl;
            // std::cout << "n = " << n << std::endl;
            int left_most_bits_idx = find_left_most_bit_idx(n);
            // std::cout << "left_most_bits_idx = " << left_most_bits_idx << std::endl;
            unsigned int bits_set = (left_most_bits_idx * (1U << (left_most_bits_idx - 1))) + 1;
            // std::cout << "bits_set = " << bits_set << std::endl;
            total_of_bits_set += bits_set + bits_in_last_num*(1U << left_most_bits_idx);
            // std::cout << "total_of_bits_set = " << total_of_bits_set << std::endl;
            n = n & (~(1U << left_most_bits_idx));
            bits_in_last_num++;
            // std::cout << "=======================================" << std::endl;
        }

        
        return total_of_bits_set;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends
