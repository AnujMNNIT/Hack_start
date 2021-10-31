#pragma GCC target("avx2")

class Solution {
public:
    int minDistance(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        
        int len1 = word1.length(); 
        int len2 = word2.length(); 
  
        int DP[2][len1 + 1]; 
  
        memset(DP, 0, sizeof DP); 
  
        for (auto i = 0; i <= len1; ++i) 
            DP[0][i] = i; 
  
        for (auto i = 1; i <= len2; ++i)
            for (auto j = 0; j <= len1; ++j) 
            { 
                if (j == 0) 
                    DP[i % 2][j] = i; 
  
                else if (word1[j - 1] == word2[i - 1]) 
                    DP[i % 2][j] = DP[(i - 1) % 2][j - 1]; 
                else 
                    DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j], 
                                       min(DP[i % 2][j - 1], 
                                           DP[(i - 1) % 2][j - 1])); 
            } 
        
        return DP[len2 % 2][len1]; 
    }
};
