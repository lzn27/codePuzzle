# 练习与题解-

部分来源于：力扣（LeetCode）

链接：https://leetcode-cn.com

```c#
//补充待整理
    //* Definition for singly-linked list.
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }
    //* Definition for a binary tree node.
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int x) { val = x; }
    }


    // Definition for a Node.
    public class Node
    {
        public int val;
        public Node next;
        public Node random;

        public Node(int _val)
        {
            val = _val;
            next = null;
            random = null;
        }
    }


    public class Solution
    {
        public int[] SpiralOrder(int[][] matrix)
        {
            if (matrix.Length == 0) return new int[] { };
            int l = 0, r = matrix[0].Length - 1, u = 0, b = matrix.Length - 1;
            int[] res = new int[matrix.Length * matrix[0].Length];
            int index = 0;
            while (l <= r && u <= b)
            {
                for(int i = l; i <= r; i++)
                {
                    res[index++] = matrix[u][i];
                }
                if (++u > b) break;
                for (int i = u; i <= b; i++)
                {
                    res[index++] = matrix[i][r];
                }
                if (--r < l) break;
                for (int i = r; i >= l; i--)
                {
                    res[index++] = matrix[b][i];
                }
                if (--b < u) break;
                for (int i = b; i >= u; i--)
                {
                    res[index++] = matrix[i][l];
                }
                if (++l > r) break;
            }
            return res;
        }

        public bool ValidateStackSequences(int[] pushed, int[] popped)
        {
            int pushIndex=0,popIndex = 0;
            Stack<int> sta = new Stack<int>();
            while (pushIndex < pushed.Length)
            {
                sta.Push(pushed[pushIndex++] );
                while (sta.Count > 0 && popIndex < popped.Length && sta.Peek() == popped[popIndex])
                {
                    sta.Pop();
                    popIndex++;
                }
            }
            return popIndex == popped.Length;
        }

        public Node CopyRandomList(Node head)
        {
            if (head == null) return null;
            Node p = head;
            while (p != null)
            {
                Node n = new Node(p.val);
                n.next = p.next;
                p.next = n;
                p = p.next.next;
            }
            p = head;
            Node p2 = head.next;
            while (p != null)
            {
                p2.random = p.random == null ? null : p.random.next;
                p = p.next.next;
                p2 = p == null ? null : p2.next.next;
            }
            Node resHead = new Node(-1);
            Node resP = resHead;
            p = head;
            p2 = head.next;
            while (p != null)
            {
                p.next = p2.next;
                resP.next = p2;
                resP = resP.next;
                p = p.next;
                p2 = p == null ? null : p.next;
            }

            return resHead.next;

        }


        public string ReplaceSpace(string s)
        {
            int spaceNum = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == ' ') spaceNum++;
            }
            List<char> res = new List<char>(s.Length + spaceNum * 2);
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == ' ')
                {
                    res.Add('%');
                    res.Add('2');
                    res.Add('0');
                }
                else
                {
                    res.Add(s[i]);
                }
            }
            return string.Join("", res);
        }


        public ListNode DetectCycle(ListNode head)
        {
            if (head == null || head.next == null) return null;
            ListNode fast = head, slow = head;
            while (fast != null && fast.next != null)
            {
                fast = fast.next.next;
                slow = slow.next;
                if (fast == slow) break;
            }
            if (fast != slow) return null;
            //有环
            ListNode slow2 = head;
            while (slow != slow2)
            {
                slow = slow.next;
                slow2 = slow2.next;
            }
            return slow2;
        }

        public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
        {
            if (headA == null || headB == null) return null;
            ListNode p1 = headA, p2 = headB;
            while (p1 != p2)
            {
                if (p1 != null) p1 = p1.next;
                else p1 = headB;
                if (p2 != null) p2 = p2.next;
                else p2 = headA;
            }
            return p1;
        }

        private int GetDigitSum(int n)
        {
            int sum = 0;
            while (n > 0)
            {
                sum += n % 10;
                n /= 10;
            }
            return sum;
        }

        public int MovingCount(int m, int n, int k)
        {
            Queue<KeyValuePair<int, int>> que = new Queue<KeyValuePair<int, int>>();
            que.Enqueue(new KeyValuePair<int, int>(0, 0));
            int res = 0;
            int[,] vis = new int[m, n];
            vis[0, 0] = 1;
            while (que.Count != 0)
            {
                var dot = que.Dequeue();
                res++;
                int i = dot.Key, j = dot.Value;
                if (i + 1 < m && j < n && vis[i + 1, j] == 0 && GetDigitSum(i + 1) + GetDigitSum(j) <= k)
                {
                    que.Enqueue(new KeyValuePair<int, int>(i + 1, j));
                    vis[i + 1, j] = 1;
                }

                if (j + 1 < n && i < m && vis[i, j + 1] == 0 && GetDigitSum(i) + GetDigitSum(j + 1) <= k)
                {
                    que.Enqueue(new KeyValuePair<int, int>(i, j + 1));
                    vis[i, j + 1] = 1;
                }
            }
            return res;
        }



        public class CQueue
        {
            private Stack<int> sta1 = new Stack<int>();
            private Stack<int> sta2 = new Stack<int>();

            public CQueue()
            {

            }

            public void AppendTail(int value)
            {
                sta2.Push(value);
            }

            public int DeleteHead()
            {
                if (sta1.Count == 0)
                {
                    while (sta2.Count != 0)
                    {
                        sta1.Push(sta2.Pop());
                    }
                    if (sta1.Count == 0) return -1;
                    else return sta1.Pop();
                }
                else
                {
                    return sta1.Pop();
                }
            }
        }

        private bool MatchWord(char[][] board, int i, int j, string word, int strIndex)
        {
            if (board.Length == 0) return false;
            if (!( i >= 0 && i < board.Length && j >= 0 && j < board[i].Length ))
                return false;
            if (board[i][j] == word[strIndex])
            {
                board[i][j] = '\0';
                bool flag = strIndex == word.Length - 1 || MatchWord(board, i + 1, j, word, strIndex + 1) || MatchWord(board, i - 1, j, word, strIndex + 1) || MatchWord(board, i, j + 1, word, strIndex + 1) || MatchWord(board, i, j - 1, word, strIndex + 1);
                board[i][j] = word[strIndex];
                return flag;
            }
            else
                return false;
        }

        public bool Exist(char[][] board, string word)
        {
            if (word.Length == 0) return false;
            for (int i = 0; i < board.Length; i++)
            {
                for (int j = 0; j < board[i].Length; j++)
                {
                    if (MatchWord(board, i, j, word, 0))
                        return true;
                }
            }
            return false;
        }

        public bool FindNumberIn2DArray(int[][] matrix, int target)
        {
            if (matrix.Length == 0) return false;
            int i = 0, j = matrix[0].Length - 1;
            while (i < matrix.Length && j >= 0)
            {
                if (matrix[i][j] > target)
                {
                    j--;
                }
                else if (matrix[i][j] == target)
                {
                    return true;
                }
                else if (matrix[i][j] < target)
                {
                    i++;
                }
            }
            return false;
        }

        public int numberOf1(int n)
        {
            //int c = 0;
            //while (n > 0)
            //{
            //    n = n & ( n - 1 );
            //    c++;
            //}
            //return c;
            int c = 0;
            while (n > 0)
            {
                if (n % 2 != 0)
                    c++;
                n = ( n >> 1 );
            }
            return c;
        }

        public void preorderTraversal(TreeNode root)
        {
            Stack<TreeNode> sta = new Stack<TreeNode>();
            TreeNode p = root;
            while (p != null || sta.Count > 0)
            {
                while (p != null)
                {
                    Console.WriteLine(p.val);
                    if (p.left != null)
                        sta.Push(p.left);
                    p = p.left;
                }
                while (p == null && sta.Count > 0) p = sta.Pop().right;
            }
        }

        public int[] TopKs(int[] nums, int top)
        {
            int indexK = TopK(nums, top);
            int[] res = new int[indexK + 1];
            Array.Copy(nums, 0, res, 0, indexK + 1);
            return res;
        }

        public int TopK(int[] nums, int top)
        {
            if (nums.Length < top) throw new Exception();
            int l = 0, r = nums.Length - 1;
            while (l < r)
            {
                int index = Partition(nums, l, r);
                if (index == top - 1) return index;
                if (index > top - 1) r = index - 1;
                else l = index + 1;
            }
            return -1;
        }

        public int Partition(int[] nums, int l, int r)
        {
            int key = nums[l];
            while (l < r)
            {
                while (l < r && nums[r] < key) r--;
                nums[l] = nums[r];
                while (l < r && nums[l] > key) l++;
                nums[r] = nums[l];
            }
            nums[l] = key;
            return l;
        }
    }


```