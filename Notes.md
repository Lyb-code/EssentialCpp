

1.2 当"内置数据类型"与"程序员自行定义的 class 类型"具备不同的初始化语法时，我们无法编写出一个template 使它同时支持"内置类型"与"class类型"。让语法统一，可以简化 template 的设计。
1.4 关键字switch之后紧接着一个由小括号括住的表达式（是的，对象名称也可视为表达式），该表达式的值必须是整数形式。
1.5 array的大小必须是个常量表达式；vector的大小并不一定得是个常量表达式。这里的array就是int数组。
vector不支持上述这种初始化列表。即int elem_seq[] = {1, 1, 2}这种初始化列表，会自动计算数组大小。
1.6 指针为程序引入了一层间接性。我们可以操作指针（代表某特定内存地址），而不再直接操作对象。
随机数生成器种子（seed）是啥？
由于下标运算符的优先级较高，因此py提领操作的两旁必须加上小括号。
1.7 和cout一样，cerr 将其输出结果定向到用户的终端。两者的唯一差别是，cerr 的输出结果并无缓冲（bufferred）情形——它会立即显示于用户终端中。







## Homework Note

- C风格的字符串，必须声明为字符数组，并必须制定长度。声明为字符指针是不行滴。—练习1.5

  ```c++
  // C-style
  void getNameInCStyle() {
      // char array instead of char pointer!!!
      char name[128];//对
      char *name;//错
      cout << "Please enter your name:";
      cin >> name;
      if (strlen(name) > 2) {
          cout << "You have entered a valid name!";
      }
  }
  ```

  string 对象和 C-style 字符串之间有两个主要差异∶（1）string 对象会动态地随字符串长度的增加而增加其储存空间，C-style 字符串却只能分配固定的空间，并期望这个固定空间可以容纳对应的字符串。（2）C-style 字符串并不记录自身长度

