cmake_minimum_required(VERSION 3.20)
project(algorithm_learn)

set(CMAKE_CXX_STANDARD 14)
add_executable(algorithm_learn main.cpp)
#12.3
add_executable(12.3.1 12.3/12.3.1.cpp) #朴素迪杰斯特拉
add_executable(12.3.2 12.3/12.3.2.cpp) #堆优化迪杰斯特拉
add_executable(12.3.3 12.3/12.3.3.cpp) #树的重心dfs
add_executable(12.3.4 12.3/12.3.4.cpp) #图的层次bfs
add_executable(12.3.5 12.3/12.3.5.cpp) #有边数限制的最短路贝尔曼富德
add_executable(12.3.6 12.3/12.3.6.cpp) #spfa求最短路
add_executable(12.3.7 12.3/12.3.7.cpp) #spfa判断负环
add_executable(12.3.8 12.3/12.3.8.cpp) #Floyd求最短路
add_executable(12.3.9 12.3/12.3.9.cpp) #Prim算法求最小生成树
add_executable(12.3.10 12.3/12.3.10.cpp) #二分图的最大匹配
add_executable(12.3.11 12.3/12.3.11.cpp) #Kruskal算法求最小生成树
add_executable(12.4.1 12.4/12.4.1.cpp) #拓展欧几里得
add_executable(12.4.2 12.4/12.4.2.cpp) #线性同余算法
add_executable(12.4.3 12.4/12.4.3.cpp) #高斯消元
add_executable(12.4.4 12.4/12.4.4.cpp) #Jeopardy of Dropped Balls(cf1500) ps我是垃圾这么简单都不会
add_executable(12.5.1 12.5/12.5.1.cpp) #Jury Meeting(cf1500)
add_executable(12.5.2 12.5/12.5.2.cpp) #Slay the Dragon(cf1300)
add_executable(12.6.1 12.6/12.6.1.cpp) #Easy Scheduling(cf1200)
add_executable(12.6.2 12.6/12.6.2.cpp) #Grandma Capa Knits a Scarf(cf1200)
add_executable(12.6.3 12.6/12.6.3.cpp) #Omkar and Heavenly Tree(cf1200)
add_executable(12.7.1 12.7/12.7.1.cpp) #Coin Rows(cf1200)
add_executable(12.7.2 12.7/12.7.2.cpp) #Two Tables(cf1300)
add_executable(12.7.3 12.7/12.7.3.cpp) #Penalty(cf1200)
add_executable(12.7.4 12.7/12.7.4.cpp) #Backspace(cf1500)
add_executable(12.9.1 12.9/12.9.1.cpp) #格子游戏
add_executable(12.10.1 12.10/12.10.1.cpp) #搭配购买
add_executable(12.11.1 12.11/12.11.1.cpp) #程序自动分析
add_executable(12.11.2 12.11/12.11.2.cpp)
add_executable(12.11.3 12.11/12.11.3.cpp)
add_executable(12.11.4 12.11/12.11.4.cpp)
add_executable(12.13.1 12.13/12.13.1.cpp) #楼兰图腾
add_executable(12.13.2 12.13/12.13.2.cpp) #一个简单的整数问题
add_executable(12.14.1 12.14/12.14.1.cpp) #一个简单的整数问题2
add_executable(12.14.2 12.14/12.14.2.cpp) #谜一样的牛
add_executable(12.15.1 12.15/12.15.1.cpp) #最大数
add_executable(12.17.1 12.17/12.17.1.cpp) #普通平衡树
add_executable(12.17.2 12.17/12.17.2.cpp)
add_executable(12.17.3 12.17/12.17.3.cpp) #ac自动机
add_executable(12.17.4 12.17/12.17.4.cpp) #ac自动机增强
add_executable(12.17.5 12.17/12.17.5.cpp) #ac自动机二次加强
add_executable(12.19.1 12.19/12.19.1.cpp) #后缀数组
add_executable(12.19.2 12.19/12.19.2.cpp) #bwt基因组压缩
add_executable(12.20.1 12.20/12.20.1.cpp) #铲雪车
add_executable(12.21.1 12.21/12.21.1.cpp) #欧拉路径
add_executable(12.21.2 12.21/12.21.2.cpp) #无序字母对
add_executable(12.21.3 12.21/12.21.3.cpp) #最短网络
add_executable(12.21.4 12.21/12.21.4.cpp) #局域网
add_executable(12.25.1 12.25/12.25.1.cpp) #de-brujin图第一次尝试
add_executable(12.27.1 12.27/12.27.1.cpp) #Wrong Addition
add_executable(12.27.2 12.27/12.27.2.cpp) #Array and Operations
add_executable(12.27.3 12.27/12.27.3.cpp) #Paprika and Permutation
add_executable(12.27.4 12.27/12.27.4.cpp) #And It's Non-Zero
add_executable(12.27.5 12.27/12.27.5.cpp) #Weights Assignment For Tree Edges
add_executable(1.6.1 1.6/1.6.1.cpp) #最优乘车
add_executable(1.6.2 1.6/1.6.2.cpp) #最优乘车解法2
add_executable(1.6.3 1.6/1.6.3.cpp) #昂贵的聘礼
add_executable(1.7.1 1.7/1.7.1.cpp) #池塘计数
add_executable(1.7.2 1.7/1.7.2.cpp) #迷宫问题
add_executable(1.7.3 1.7/1.7.3.cpp) #武士风度的牛
add_executable(1.7.4 1.7/1.7.4.cpp) #抓住那头牛
add_executable(1.8.1 1.8/1.8.1.cpp) #矩阵距离
add_executable(1.8.2 1.8/1.8.2.cpp) #魔板
add_executable(1.8.3 1.8/1.8.3.cpp) #字串变换
add_executable(1.9.1 1.9/1.9.1.cpp) #八数码
add_executable(1.9.2 1.9/1.9.2.cpp) #八数码A*优化
add_executable(1.9.3 1.9/1.9.3.cpp) #迷宫
add_executable(1.9.4 1.9/1.9.4.cpp) #红与黑
add_executable(1.9.5 1.9/1.9.5.cpp) #马走日
add_executable(1.9.6 1.9/1.9.6.cpp) #单词接龙
add_executable(1.9.7 1.9/1.9.7.cpp) #分成互质组
add_executable(1.10.1 1.10/1.10.1.cpp) #小猫爬山
add_executable(1.10.2 1.10/1.10.2.cpp) #求先序排列
add_executable(1.10.3 1.10/1.10.3.cpp) #Integers Shop
add_executable(1.10.4 1.10/1.10.4.cpp) #Representative Edges
add_executable(1.15.1 1.15/1.15.1.cpp)
add_executable(1.15.2 1.15/1.15.2.cpp)
add_executable(1.15.3 1.15/1.15.3.cpp)
add_executable(1.18.1 1.18/1.18.1.cpp) #加成序列
add_executable(1.18.2 1.18/1.18.2.cpp) #送礼物
add_executable(1.18.3 1.18/1.18.3.cpp) #新年好
add_executable(1.18.4 1.18/1.18.4.cpp) #牛的旅行
add_executable(1.18.5 1.18/1.18.5.cpp) #Running for Gold
add_executable(1.18.6 1.18/1.18.6.cpp) #Interesting Story
add_executable(1.19.1 1.19/1.19.1.cpp) #后缀自动机板子
add_executable(1.19.2 1.19/1.19.2.cpp) #玄武密码
add_executable(1.19.3 1.19/1.19.3.cpp) #最长公共子串
add_executable(1.20.1 1.20/1.20.1.cpp) #Agent2
add_executable(1.20.2 1.20/1.20.2.cpp) #语文成绩
add_executable(1.20.3 1.20/1.20.3.cpp) #水题
add_executable(1.20.4 1.20/1.20.4.cpp) #素数密度
add_executable(1.20.5 1.20/1.20.5.cpp)
add_executable(1.21.1 1.21/1.21.1.cpp)
add_executable(1.21.2 1.21/1.21.2.cpp) #夏洛克和他的女朋友
add_executable(1.21.3 1.21/1.21.3.cpp) #哥德巴赫猜想
add_executable(1.21.4 1.21/1.21.4.cpp) #阶乘分解
add_executable(1.21.5 1.21/1.21.5.cpp) #序列的第k个数
add_executable(1.21.6 1.21/1.21.6.cpp) #越狱
add_executable(1.22.1 1.22/1.22.1.cpp)
add_executable(1.30.1 1.30/1.30.1.cpp) #受欢迎的牛
add_executable(1.30.2 1.30/1.30.2.cpp) #The Cow Prom S
add_executable(1.30.3 1.30/1.30.3.cpp) #割点
add_executable(1.31.1 1.31/1.31.1.cpp) #学校网络
add_executable(1.31.2 1.31/1.31.2.cpp) #最大半连通子图
add_executable(2.2.1 2.2/2.2.1.cpp)#笨拙的手指
add_executable(2.2.2 2.2/2.2.2.cpp)#干草堆
add_executable(2.2.3 2.2/2.2.3.cpp)#奶牛选美
add_executable(2.2.4 2.2/2.2.4.cpp)#拖拉机
add_executable(2.2.5 2.2/2.2.5.cpp)#拖拉机最短路尝试
add_executable(2.4.1 2.4/2.4.1.cpp)#岛
add_executable(2.4.2 2.4/2.4.2.cpp)#马蹄铁
add_executable(2.4.3 2.4/2.4.3.cpp)#打乱字母
add_executable(2.4.4 2.4/2.4.4.cpp)#奶牛棒球
add_executable(2.4.5 2.4/2.4.5.cpp)#粉刷栅栏
add_executable(2.4.6 2.4/2.4.6.cpp)#九小时九个人九扇门
add_executable(2.4.7 2.4/2.4.7.cpp)#炸鸡块君的高中回忆
add_executable(2.4.8 2.4/2.4.8.cpp)#牛牛学走路
add_executable(2.4.9 2.4/2.4.9.cpp)#小朋友做游戏
add_executable(2.4.10 2.4/2.4.10.cpp)#牛牛看云
add_executable(3.2.1 3.2/3.2.1.cpp)#造gfa数据
add_executable(3.4.1 3.4/3.4.1.cpp)#Inversion Graph
add_executable(3.4.2 3.4/3.4.2.cpp)#Andrew and Stones
add_executable(3.4.3 3.4/3.4.3.cpp)#Differential Sorting
add_executable(3.4.4 3.4/3.4.4.cpp)#Fortune Telling
add_executable(3.5.1 3.5/3.5.1.cpp)#Factorials and Powers of Two
add_executable(3.5.2 3.5/3.5.2.cpp)#Square Counting
add_executable(3.5.3 3.5/3.5.3.cpp)#Quality vs Quantity
add_executable(3.5.4 3.5/3.5.4.cpp)#Increase Subarray Sums
add_executable(3.5.5 3.5/3.5.5.cpp)#Doors and Keys
add_executable(3.5.6 3.5/3.5.6.cpp)#Anti-Fibonacci Permutation
add_executable(3.5.7 3.5/3.5.7.cpp)#Power Walking
add_executable(3.5.8 3.5/3.5.8.cpp)#Cross Coloring
add_executable(3.5.9 3.5/3.5.9.cpp)#Hard Way
add_executable(3.5.10 3.5/3.5.10.cpp)#Menorah
add_executable(3.6.1 3.6/3.6.1.cpp)#Road Optimization
add_executable(3.6.2 3.6/3.6.2.cpp)#Game
add_executable(3.6.3 3.6/3.6.3.cpp)#Game of Ball Passing
add_executable(3.6.4 3.6/3.6.4.cpp)
add_executable(3.6.5 3.6/3.6.5.cpp)
add_executable(gsam 3.7/gsam.cpp)
add_executable(gfa_loader 3.7/gfa_loader.cpp)
add_executable(3.8.1 3.8/3.8.1.cpp)#后缀自动机及索引版本
add_executable(3.8.2 3.8/3.8.2.cpp)#广义后缀自动机索引版本
add_executable(3.8.3 3.8/3.8.3.cpp)#cfA
add_executable(3.8.4 3.8/3.8.4.cpp)#cfB
add_executable(3.8.5 3.8/3.8.5.cpp)#cfC
add_executable(3.8.6 3.8/3.8.6.cpp)#cfD
add_executable(3.8.7 3.8/3.8.7.cpp)#cfE
add_executable(3.9.1 3.9/3.9.1.cpp)#水题
add_executable(3.9.2 3.9/3.9.2.cpp)#水题
add_executable(3.9.3 3.9/3.9.3.cpp)#水题
add_executable(3.9.4 3.9/3.9.4.cpp)#水题
add_executable(3.10.1 3.10/3.10.1.cpp)#水题
add_executable(3.10.2 3.10/3.10.2.cpp)#水题
add_executable(3.10.3 3.10/3.10.3.cpp)#路径统计
add_executable(3.10.4 3.10/3.10.4.cpp)#买礼物
add_executable(3.10.5 3.10/3.10.5.cpp)#口袋的天空
add_executable(3.10.6 3.10/3.10.6.cpp)#公路修建
add_executable(3.10.7 3.10/3.10.7.cpp)#Watering the Fields S
add_executable(3.10.8 3.10/3.10.8.cpp)#水题
add_executable(3.10.9 3.10/3.10.9.cpp)#Timeline G
add_executable(3.10.10 3.10/3.10.10.cpp)
add_executable(3.10.11 3.10/3.10.11.cpp)
add_executable(3.11.1 3.11/3.11.1.cpp)
add_executable(first_edition suffix_auto_machine/first_edition.cpp)
add_executable(second_edition suffix_auto_machine/second_edition.cpp)
add_executable(third_edition suffix_auto_machine/third_edition.cpp)
add_executable(four_edition suffix_auto_machine/fourth_edition.cpp)
add_executable(firth_edition suffix_auto_machine/fifth_edition.cpp)
add_executable(3.11.2 3.11/3.11.2.cpp)
add_executable(3.11.3 3.11/3.11.3.cpp)
add_executable(3.11.4 3.11/3.11.4.cpp)
add_executable(3.11.5 3.11/3.11.5.cpp)
add_executable(3.11.6 3.11/3.11.6.cpp)
add_executable(3.11.7 3.11/3.11.7.cpp)
add_executable(3.11.8 3.11/3.11.8.cpp)
add_executable(3.11.9 3.11/3.11.9.cpp)
add_executable(3.12.1 3.12/3.12.1.cpp)
add_executable(suffix_balanced_tree suffix_balanced_tree/solve.cpp)
add_executable(3.12.2 3.12/3.12.2.cpp)
add_executable(3.12.3 3.12/3.12.3.cpp)
add_executable(3.12.4 3.12/3.12.4.cpp)
add_executable(3.12.5 3.12/3.12.5.cpp)
add_executable(3.13.1 3.13/3.13.1.cpp)
add_executable(3.13.2 3.13/3.13.2.cpp)
add_executable(3.13.3 3.13/3.13.3.cpp)
add_executable(3.13.4 3.13/3.13.4.cpp)
add_executable(fifth_edition_fprintf_optimal suffix_auto_machine/fifth_edition_fprintf_optimal.cpp)
add_executable(directed_acyclic_word_graph DAWG/directed_acyclic_word_graph.cpp)
add_executable(count_string suffix_auto_machine/count_string.cpp)
add_executable(3.14.1 3.14/3.14.1.cpp)
add_executable(3.14.2 3.14/3.14.2.cpp)
add_executable(global_count_string suffix_auto_machine/global_count_string.cpp)
add_executable(3.20.1 3.20/3.20.1.cpp)
add_executable(3.20.2 3.20/3.20.2.cpp)
add_executable(3.20.3 3.20/3.20.3.cpp)
add_executable(create_data create_data/split_data.cpp)
add_executable(test_io create_data/test.cpp)
add_executable(count_graph create_data/create_data.cpp)
add_executable(3.15.1 3.15/3.15.1.cpp)
add_executable(3.15.2 3.15/3.15.2.cpp)
add_executable(3.15.3 3.15/3.15.3.cpp)
add_executable(3.15.4 3.15/3.15.4.cpp)
add_executable(4.8.1 4.8/4.8.1.cpp)
add_executable(4.8.2 4.8/4.8.2.cpp)