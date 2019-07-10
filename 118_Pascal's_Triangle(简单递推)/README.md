# 118. Pascal's Triangle(leetcode easy)
看代码，vector先分配好内存后会初始化为0，直接访问位置使用，使用push_back会加到初始化的0的后面。