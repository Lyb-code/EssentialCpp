## 第1章 C++编程基础

**1.2 对象的定义与初始化**

当"内置数据类型"与"程序员自行定义的 class 类型"具备不同的初始化语法时，我们无法编写出一个template 使它同时支持"内置类型"与"class类型"。让语法统一，可以简化 template 的设计。

**1.4 条件语句和循环语句**

关键字switch之后紧接着一个由小括号括住的表达式（是的，对象名称也可视为表达式），该表达式的值必须是整数形式。

**1.5 如何使用Array和Vector**

array的大小必须是个常量表达式；vector的大小并不一定得是个常量表达式。这里的array就是int数组。
vector不支持上述这种初始化列表。即int elem_seq[] = {1, 1, 2}这种初始化列表，会自动计算数组大小。

**1.6 指针带来弹性**

指针为程序引入了一层间接性。我们可以操作指针（代表某特定内存地址），而不再直接操作对象。
随机数生成器种子（seed）是啥？
由于下标运算符的优先级较高，因此pv提领操作的两旁必须加上小括号。

**1.7 文件的读写**

和cout一样，cerr 将其输出结果定向到用户的终端。两者的唯一差别是，cerr 的输出结果并无缓冲（bufferred）情形——它会立即显示于用户终端中。



## 第2章 面向过程编程风格

**2.2 调用函数**

当我们以 byreference 方式将对象作为函数参数传入时，对象本身并不会复制出另一份——复制的是对象的地址。函数中对该对象进行的任何操作，都相当于是对传入的对象进行间接操作。

pointer参数和 reference 参数之间更重要的差异是，**pointer 可能（也可能不）指向某个实际对象**。当我们提领 pointer时，一定要先确定其值并非0。**至于reference，则必定会代表某个对象**，所以不需要做此检查。

范围(extent)和作用域(scope)的区别。file scope 内的对象也具备所谓的 static extent；从 heap分配而来的对象，被称为具有 dynamic extent。

C++没有提供任何语法让我们得以从 heap 分配数组的同时为其元素设定初值。

**2.3 提供默认参数值**

一般的程序编写法则是，**以"参数传递"作为函数间的沟通方式，比"直接将对象定义于 file scope"更适当**。理由之一是，函数如果过度依赖定义于file scope 内的对象，就比较难以在其他环境中重用，也比较难以修改——我们不仅需要了解该函数的工作逻辑，也必须了解定义于file scope 中的那些对象的工作逻辑。

关于默认参数值的提供，有两个不很直观的规则。第一个规则是，默认值的解析（resolve）操作由最右边开始进行。如果我们为某个参数提供了默认值，那么这一参数右侧的所有参数都必须也具有默认参数值才行。第二个规则是，**默认值只能够指定一次、可以在函数声明处，亦可以在函数定义处，但不能够在两个地方都指定**。为了更高的可见性，我们决定将默认值放在函数声明处而非定义处。

我们之所以包含cstdlib头文件，正是为了要包含exit（）函数声明。函数的定义通常被放在程序代码文件，该文件只被编译一次，当我们想要使用该函数时，会将它链接（link）到我们的程序来。也就是说，头文件可为函数带来更高的可见性（visiblity）。

**2.4 使用局部静态对象**

是的，为了节省函数间的通信问题而将对象定义于 file scope内，永远都是一种冒险。通常，file scope 对象会打乱不同函数间的独立性，使它们难以理解。

**2.5 声明inline函数**

inline 函数的定义，常常被放在头文件中。由于**编译器必须在它被调用的时候加以展开**，所以这个时候其定义必须是有效的。

**2.6 提供重载函数**

为什么返回类型不足以将函数重载呢?因为返回类型无法保证提供给我们一个足以区分不同重载函数的语境。例如

```c++
display_message（'\t'）;//无返回值
```

**2.7 定义和使用函数模板**

function template 将参数列表中指定的全部（或部分）参数的类型信息抽离了出来。

function template 以关键字template开场，其后紧接着以成对尖括号（<>）包围起来的一个或多个标识符。这些标识符用以表示我们希望推迟决定的数据类型。

编译器会将elemType绑定（bind）为int类型，然后产生一份 display_message（）函数实例，于是其第二参数的类型即变成 vector< int >。

一般而言，如果函数具备多种实现方式，我们可将它重载（overload ），其每份实例提供的是相同的通用服务。如果我们希望让程序代码的主体不变，仅仅改变其中用到的数据类型，可以通过 function template 达到目的。当然，function template 同时也可以是重载函数。

**2.8 函数指针带来更大的弹性**

```cpp
const vector<int>* *seq_ptr( int );//错误，这个声明的是个函数。几乎是对的了
const vector<int>* (*seq_ptr)( int );// ok
//将 pell_seq（）的地址赋值给seq_ptr
seq_ptr = pell_seq;
// seq_array是个数组，内放函数指针
const vector<int>* (*seq_array[])(int) = {fibon_seg,lucas_8seq, pell_seq};
```

由函数指针指向的函数，其调用方式和一般函数相同。

如何取得函数的地址呢?这是C++中最不复杂的操作了、只要提供函数名称即可。

默认情形下，第一个枚举项的值为0，接下来的每个枚举项都比前一个多。

**2.9 设定头文件**

头文件的扩展名，习惯上是.h。标准库例外，它们没有扩展名

函数的定义只能有一份。不过倒是可以有许多份声明。我们不把函数的定义放入头文件，因为同一个程序的多个代码文件可能都会包含这个头文件。**"只定义一份"的规则有个例外：inline 函数的定义。**为了能够扩展 inline 函数的内容，在每个调用点上，编译器都得取得其定义。这意味着**我们必须将 inline 函数的定义放在头文件中**，**而不是把它放在各个不同的程序代码文件中**。

在 file scope 内定义的对象，如果可能被多个文件访问，就应该被声明于头文件中。

这并不正确，因为它会被解读为seq_array的定义而非声明。**就像函数一样，一个对象只能在程序中被定义一次。**对象的定义，就像函数定义一样，必须放在程序代码文件中。只要在上述seq_array定义前加上关键字 extern，它便成为一个声明。

为什么seq_cnt不需要加上关键字extern呢？**const object就和inline函数一样，是"一次定义"规则下的例外**。**const object的定义只要一出文件之外便不可见**。这意味着我们可以在多个程序代码文件中加以定义，不会导致任何错误。为什么我们会想要那么做呢?因为我们希望编译器在我们的数组声明中使用这一const object。并且在其他需要用到常量表达式（constant expression）的场合中（那可能会跨文件）也能够使用。

书上P64说明了使用<>和双引号""包含头文件的区别。



## 第3章 泛型编程风格

Standard Template Library（STL）主要由两种组件构成∶一是容器（container）。包括vector、list、set、map 等类；另一种组件是用以操作这些容器的所谓泛型算法（generic algorithm）、包括find（）、sort（）、replace（）、merge （）等。

在顺序性容器（sequential container）身上主要进行所谓的迭代（iterate）操作，vector 、list、deque；关联容器（associative container）可以让我们快速查找容器中的元素值，map和set。

泛型算法系通过 function template技术，达到"与操作对象的类型相互独立"的目的。而**实现"与容器无关"的诀窍，就是不要直接在容器身上进行操作。而是借由一对 iterator（first和 last） 标示我们要进行迭代的元素范围**。

**3.1 指针的算术运算**

当数组被传给函数。或是由函数中返回，仅有第一个元素的地址会被传递。

```cpp
int min (int array[24]){...}//array并不会以传值方式复制一份，而且我们可以传递[任意大小]的 array给min（）
```

下标操作就是将 array 的起始地址加上索引值，产生出某个元素的地址。然后该地址再被提领（dereference）以返回元素值。

在让我们扩展 find（）的功能，令它也能支持标准库所提供的 list 类别。指针的算术运算并不适用于list。因为**指针的算术运算必须首先假设所有元素都储存在连续空间里，然后才能根据当前的指针，加上元素大小之后，指向下一个元素**。解决这个问题的办法是，在底层指针的行为之上提供一层抽象，取代程序原本的"指针直接操作"方式。我们把底层指针的处理通通放在此抽象层中，让用户无须直接面对指针操作。这个技巧使得我们只需提供一份find（）函数，便可以处理标准库所提供的所有容器类.

**3.2 Iterator(泛型指针)**

把Iterator理解为在底层指针的行为之上提供的一层抽象，取代了程序原本的"指针直接操作"方式。我们把底层指针的处理通通放在此抽象层中，让用户无须直接面对指针操作。

function object（这是一种特殊的 class）。

标准库提供的find_if（），能够接受函数指针或 function object，取代底部元素的equality 运算符，大大提升弹性。

**3.4 使用顺序性容器**

vector、list和deque。deque 的行为和 vector颇为相似——都以连续内存储存元素。

pop_back（）和pop_front（）这两个操作函数并不会返回被删除的元素值。因此，如果要读取最前端元素的值，应该采用 front（）。如果要读取末端元素的值，应该采用 back（）。

list并不支持 iterator 的偏移运算。

**3.5 使用泛型算法**

```c++
vector<int> temp( vec.size());//确保"目标容器"拥有足够空间以放置每个即将到来的元素，这是程序员的责任。
copy( vec.begin(),vec.end(),tetmp.begin());
```

**3.6 如何设计泛型算法**

Function Object：某种 class的实例对象，这类class**对 function call运算符做了重载操作**，如此一来可使 function object 被当成一般函数来使用。function object 实现了我们原本可能以独立函数加以定义的事物。但又何必如此呢？**主要是为了效率**。我们**可以令 call运算符成为 inline，从而消除"通过函数指针来调用函数"时需付出的额外代价**。

function object adapter 会对 function object 进行修改操作。所谓 binder adapter（绑定适配器）会将function object 的参数绑定至某特定值，使 binary（二元）function object转化为 unary（一元）function object。

为了消除它和元素类型间的依赖性，我们将 filter（）改为 function template。为了消除它和容器类型间的依赖性，我们传人一对iteartor【first，last）。

**3.9 Iterator Inserter**

标准库提供了三个所谓的 insertion adapter，这些 adapter 让我们得以避免使用容器的 assignment 运算符。

然而这些 adapter并不能用在 array上。array并不支持元素插入操作。



## 第4章 基于对象的编程风格

**4.1 如何实现一个class**

前置声明使我们得以进行类指针（class pointer）的定义，或以此class 作为数据类型。

private member 只能在 member function或是 class friend内被访问。

所有member function 都必须在 class 主体内进行声明。**至于是否要同时进行定义，可自由决定**。**如果要在 class 主体内定义，这个 member function 会自动地被视为 inline 函数**。

class定义及其 inline member function 通常都会被放在与class同名的头文件中。**non-inline member function 应该在程序代码文件中定义**，该文件通常和 class 同名，其后接着扩展名.c、.cc、.cpp或.cxx（x代表横放的+）。

**4.2 构造函数与析构函数**

```cpp
//以下程序代码无法成功定义一个Triangular object∶
Triangular t5（）;//此行将 t5定义为一个函数，其参数列表是空的，返回Triangular object。
Triangular t5;// 正确（符合我们意图）的t5声明方式
```

**Memberwise Initialization（成员逐一初始化）**：如果Matrix设计者提供了一个copy constructor，它就可以改变"成员逐一初始化"的默认行为模式。

当我们设计class时，必须向问自己，在此 class之上进行"成员逐一初始化"的行为模式是否适当?如果答案肯定，我们就不需要另外提供copy constructor。但如果答案是否定的，我们就必须另行定义 copy constructor，并在其中编写正确的初始化操作。

如果有必要为某个class 编写copy constructor，那么同样有必要为它编写**copy assignment operator**（参阅 4.8节）。

**4.3 mutable与const**

val（）并不直接修改_val，但它却会返回一个 non-const reference 指向 _val。那么，val（）可被声明为const吗? **不，这会产生问题（但语法层面正确），返回一个non-const reference 指向 _val.实际上等于将 _val开放出去，允许程序在其他地方加以修改**。有个方法可以解决这个问题∶提供两份定义，一为const版本，一为 non-const版本。**non-const class object 会调用non-const版的val（）**（于是对象内容被改变也没有关系），**const class object则会调用const版的val（）**（那就不可能改变对象的内容）。

**Mutable Data Member**: 改变 next的值，从意义上来说，不能视为改变 class object的状态，或者说不算是破坏了对象的常量性（constness）。关键字mutable可以让我们做出这样的声明。**只要将next标示为mutable，我们就可以宣称∶对next所做的改变并不会破坏class object 的常量性**。

**4.5 静态类成员**

当我们在 class主体外部进行静态member function的定义时，无须重复加上关键字static（这个规则也适用于 static data member ）。

**4.6 打造Iterator class**

运算符函数看起来很像普通函数、唯一差别是它不用指定名称，只需在运算符前加上关键字operator 即可。

increment（递增）运算符的前置（++trian）和后置（trian++）两个版本。后置版的参数列表原本也应该是空的，然而重载规则要求，参数列表必须独一无二。因此，C++语言想出一个变通办法，要求**后置版得有一个int参数**。编译器会自动为后置版产生一个int参数（其值必为0）。

**4.7 friend**

因为任何 class 都可以将其他function 或class指定为朋友（friend）。而所谓 friend，具备了与class member function 相同的访问权限，可以访间 class的 private member。

**友谊的建立，通常是为了效率考虑**。例如在某个 non-member 运算符函数中进行 Point 和Matrix的乘法运算。如果我们只是希望进行某个 data member 的读取和写入，那么，为它提供具有 public 访问权限的 inline 函数，就是建立友谊之外的一个替代方案。问题：**没太理解是怎么能提高效率**。

**4.10 重载iostream运算符**

**传入函数的ostream对象又被原封不动地返回**。如此一来我们便得以串接多个 output 运算符。参数列表中的两个对象皆以传址（by reference）方式传入。**其中的ostream对象并未声明为const**，因为每个output操作都会更改ostream对象的内部状态。

为什么**不把 output 运算符设计为一个member function**呢?因为**作为一个member function，其左操作数必须是隶属于同一个class 的对象**。如果 output 运算符被设计为tri class member function，那么tri object 就必须被放在 output 运算符的左侧。

**4.11 指针，指向类的成员函数**

```cpp
void (num_sequence::*pm)( int )= 0;//指向 num sequence的member function
PtrType pm = &num_sequence::fibonacci;
```

基于所谓的 maximal munch 编译规则。此规则要求，每个符号序列（symbol sequence）总是以"合法符号序列"中最长的那个解释。因为>>是个合法的运算符序列，因此如果两个>之间没有空白，这两个符号必定会被合在一起看待。

Pointer to member function和 pointer to function的一个不同点是，前者必须通过同一类的对象加以调用，而该对象便是此 member function 内的this指针所指之物。



## 第5章 面向对象编程风格

**5.1 面向对象编程概念**

**多态**让我们在这些类之上进行编程时，**可以如同操控单一个体，而非相互独立的类、并赋予我们更多弹性来加入或移除任何特定类**。多态（polymorphism）: 让基类的 pointer 或 reference 得以十分透明地（transparently）指向其任何一个派生类的对象。

在面向对象应用程序中，我们会**间接利用「指向抽象基类"的 pointer 或 reference 来操作系统中的各对象，而不直接操作各个实际对象。**这让我们得以在不更动旧有程序的前提下，加入或移除任何一个派生类。

**多态和动态绑定的特性，只有在使用 pointer 或reference时才能发挥**。

**5.2 漫游：面向对象编程思维**

**虚函数**：默认情形下，member function 的解析（resolution）皆在编译时静态地进行。若要令其在运行时动态进行，我们就得在它的声明前加上关键字virtual。

**5.4 定义一个抽象基类**

当程序定义出一个派生对象，基类和派生类的 constructor 都会被执行。（当派生对象被销毁，基类和派生类的 destructor也都会被执行【但次序颠倒】）

注意，static member function 无法被声明为虚拟函数。说明如下：

```cpp
首先什么是static静态成员函数？静态成员函数不属于类中的任何一个对象和实例，属于类共有的一个函数。也就是说，它不能用this指针来访问，因为this指针指向的是每一个对象和实例。

对于virtual虚函数，它的调用恰恰使用this指针。在有虚函数的类实例中，this指针调用vptr指针，指向的是vtable(虚函数列表)，通过虚函数列表找到需要调用的虚函数的地址。总体来说虚函数的调用关系是：this指针->vptr(4字节）->vtable ->virtual虚函数。

所以说，static静态函数没有this指针，也就无法找到虚函数了。所以静态成员函数不能是虚函数。他们的关键区别就是this指针。

原文链接：https://blog.csdn.net/flf1234567898/article/details/108396847
```

根据一般规则，**凡基类定义有一个（或多个）虚函数，应该要将其destructor声明为virtual**，**说明**如下。此外，virtual destructor 最好不要声明为纯虚函数。

```tex
基类指针可以指向派生类的对象（多态性），如果删除该指针delete p；就会调用该指针指向的派生类析构函数，而派生类的析构函数又自动调用基类的析构函数，这样整个派生类的对象完全被释放。如果析构函数不被声明成虚函数，则编译器实施静态绑定，在删除基类指针时，只会调用基类的析构函数而不调用派生类析构函数，这样就会造成派生类对象析构不完全。所以，将析构函数声明为虚函数是十分必要的。
```

**5.5 定义一个派生类**

派生类由两部分组成∶一是基类构成的子对象（subobjcct），由基类的 non-static data member——如果有的话——组成、二是派生类的部分（由派生类的 non-static data member 组成）。

重新设计的方式之一便是在基类 num sequence内加上两个纯虚函数length（）和beg_pos（）。这样一来便会**"自动"造成派生类的beg_pos（）和length（）都成为虚拟函数**——它们不需要再指定关键字 virtual。

在类之外对虚函数进行定义时，不必指明关键字virtual。

```cpp
int FIbonacei::elem( int pos ) const
{
	if (! check integrity( pos ))
		return 0;
	if (pos >_elems.size ())
		Fibonacci;;gen_elems( pos );//必须写成 Fibonacci∶∶gen_elems（pos），不能简单地写gen_elems（pos）
    //通过 class scope 运算符，我们可以明确告诉编译器，我们想调用哪一份函数实例。于是，运行时发生的虚拟机制便被遮掩了。
	return _elems[ pos-1]; 
}
```

"这种解决方法带来的问题是，在基类中 check_integrity（）并未被视为虚函数。于是，每次通过基类的 pointer或 reference 来调用 check integrity（），解析出来的都是基类num_sequence 的那一份，未考虑到 pointer 或 reference 实际指向的究竟是什么对象"。

**5.7 基类应该多么抽象**

为什么它被声明为 reference 而非 pointer 呢?正如我在 2.3 节所说，reference永远无法代表空对象（nullobject ），pointer 却有可能是 null。**让它成为 reference.我们就再也不必检查它是否为 null了。**

Data member 如果是个reference，必须在constructor 的member initialization list 中加以初始化

**5.9 在派生类中定义一个虚函数**

"返回类型必须完全吻合"这一规则有个例外———当基类的虚函数返回某个基类形式（通常是pointer或reference ）时，派生类中的同名函数便可以返回该基类所派生出来的类型。

当我们在派生类中，为了覆盖基类的某个虚函数，而进行声明操作时，不一定得加上关键字virtual。编译器会依据两个函数的**原型声明**，决定某个函数是否会覆盖其基类中的同名函数。

**虚函数的静态解析**（Static Resolution ）。有两种情况，虚函数机制不会出现预期行为∶（1）**基类的constructor 和destructor 内**。在基类的 constructor 中，派生类的虚函数绝对不会被调用。如果在基类的 destructor 中调用虚函数，此规则同样成立。例如 num_sequence的constructor 内如果调用 what_am_i（），无论如何一定会被解析为 num_sequence自身的那一份what_am_i（）。当我们构造派生类对象时，基类的 constructor 会先被调用，此刻派生类中的 data member 尚未初始化。如果此时调用派生类的那一份虚函数，它便有可能访问未经初始化的 data member，这可不是一件好事。（2）当我们使用的是基类的对象，而非基类对象的 pointer或 reference 时。

```cpp
void print( LibMat object, const LibMat *pointer, const LibMat &reference )
{
    // 以下必定调用 LibMat∶∶print（）
	object.print();
    // 以下一定会通过虚函数机制来进行解析，
    // 我们无法预知哪一份print（）会被调用。
    pointer->print ();
	reference.print ();
}
```

当我们为基类声明一个实际对象（例如 print（）的第一参数object），同时也就分配出了足以容纳该实际对象的内存空间。如果稍后传入的却是个派生类对象，那就没有足够的内存放置派生类中的各个 data member。只有派生类对象内的"基类子对象（也就是属于LibMat的成分）"被复制到"为参数object而保留的内存"中。其他的子对象（Book成分和 AudioBook成分）则被切掉（sliced off）了。

**5.10 运行时的类型鉴定机制RTTI**

typeid 运算符它让我们得以查询多态化的 class pointer 或 class reference，获得其所指对象的实际类型。

```cpp
if( Fibonacci*pf= dynamic cast<Fibonacci*>( ps ))
	pf->gen_elems( 64 );
```

dynamic_cast 也是一个 RTTI 运算符，它会进行运行时检验操作，检验 ps所指对象是否属于Fibonacci类。如果是，转换操作便会发生，于是pf便指向该Fibonaci对象。如果不是，dynamic_cast运算符返回0。



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

- global scope（全局作用域）运算符

  ```c++
  bool Stack::find(const string& elem) const {
      vector<string>::const_iterator end_it = _stack.end();
      return ::find(_stack.begin(), end_it, elem) != end_it;
  }
  
  int Stack::count(const string & elem) const {
      return ::count(_stack.begin(), _stack.end(), elem);
  }
  ```

  为了调用这两个泛型算法，我必须**使用global scope（全局作用域）运算符**。如果不这么做会怎样?啊，在 find（）之中调用未以 global scope 运算符限定的 find（），会递归调用到自己!
