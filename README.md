# 这是一个自用的扫雷软件

1. 用c语言编写
2. 目前还未写完(截至日期2024.5.13)





## 参考







## 未来

1. 考虑用QT来重构其UI

 ## BUG

1. *game_end     22(已修复)* 

```c
  landmine_around_num += (int)(list_hide[y + i][x + j]-'0')
```

- *有bug，但原因不明，猜测是由于内存越界。*
- *明天修(记录时间2024.5.13)。*

2. 循环自动找出给定点的周围的周围雷数为0的点自动显示的函数有问题，无法正确运行

   ```c
   game_end.c/void recursive_LANumber(int x, int y, int line, int column, char **list_hide, char **list)有问题。
   ```

   - 待修复
   - 明天修
   - 记录时间(2024.5.14)
   - 
   - bug 需要优化性能，递归计算有bug(2024.5.16)

   

   
   
   ## 目前暂停更新，循环的性能问题，貌似要用BFS算法结局，准备开始研读算法，暂停更新
   
   
   
   
   
   



