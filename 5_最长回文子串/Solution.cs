//动态规划
public class Solution
{
    public string LongestPalindrome(string s)
    {
        bool[,] dp = new bool[s.Length, s.Length];
        string ans = s.Substring(0, 1);
        for(int k = 0; k < s.Length; k++)
        {
            for(int i = 0; i + k < s.Length; i++)
            {
                int j = i + k;
                if (i == j) dp[i, i] = true;
                if (j - i == 1) dp[i, j] = (s[i] == s[j]);
                if (j - i > 1) dp[i, j] = ( s[i] == s[j] && dp[i + 1, j - 1] );//dp
                if (dp[i, j] && j - i + 1 > ans.Length) ans = s.Substring(i, j - i + 1);
            }
        }
        return ans;
    }
}