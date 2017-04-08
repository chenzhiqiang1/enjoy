/*
题目描述：
    亲们！！我们的外国友人YZ这几天总是睡不好,初中奥数里有一个题目一直困扰着他,特此他向JOBDU发来求助信,希望亲们能帮帮他。问题是：求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

输入：
    输入有多组数据,每组测试数据为一行。
    每一行有两个整数a,b(0<=a,b<=1,000,000,000)。

输出：
    对应每个测试案例,输出a和b之间1出现的次数。

样例输入：
    0 5
    1 13
    21 55
    31 99

样例输出：
    1
    6
    4
    7

 思路：我们先写一个函数，求出从1到整数n之间1出现的次数，而后分别将要求输入的两个数（具体说，应该是最大的数，和最小的数减去1）作为参数传入该函数，得到的值相减，即可得到二者之间的的数中1出现的次数。
    最简单的方法，分别求从1到n之间每个数中的1的个数，由于整数n的位数为O(logn)，我们要判断一个数有多少个1，需要判断其每一位是否为1，这样一个数就需要判断O(logn)次，而总共有n个数需要求，那么该方法的时间复杂度为O(nlogn)。在九度OJ上用该方法写的代码测试，会超时。
    剑指offer上给了一种递归的思路，能将时间复杂度降到O(logn)，总感觉这个思路有点偏，而且很难想到，我没仔细看。我的想法是各位分开统计，而且看到何海涛博客下面很多人留言，也用了这样的方法，就看了下详细的思路，并自己推导了下公式，写出了代码，感觉这种方法还是很nice的，直观易懂，而且代码简洁，时间复杂度同为O(logn)。
    这种方法的思路大概是这样的（懒得动手打了，直接copy）：
    按每一位来考虑，
    1)此位大于1，这一位上1的个数有 ([n / 10^(b+1) ] + 1) * 10^b
    2)此位等于0，为 ([n / 10^(b+1) ] ) * 10^b
    3)此位等于1，在0的基础上加上n mod 10^b + 1

    举个例子：
    30143:
    由于3>1,则个位上出现1的次数为(3014+1)*1
    由于4>1,则十位上出现1的次数为(301+1)*10
    由于1=1，则百位上出现1次数为(30+0)*100+(43+1)
    由于0<1，则千位上出现1次数为(3+0)*1000

    注:以百位为例，百位出现1为100~199，*100的意思为单步出现了100~199，100次，*30是因为出现了30次100~199,+(43+1)是因为左后一次301**不完整导致。
    如果还不懂，自己拿纸和笔大致写下，找下规律，就能推导出来了！
    两外，需要注意一点：由于测试系统要求的输入数据最大为1,000,000,000，因此用int会溢出，要用long long，另外比较坑跌的一点是a可能比b大，居然都没有说明，有点坑了。
*/

#include<stdio.h>

/*
分别统计num各位上1出现的次数，
相加得到1出现的总次数
*/
long long CountNum1(long long num)
{
	if(num <= 0)
		return 0;

	long long count = 0;	//统计1出现的次数
	long long current;    //当前位
	long long base = 1;	//当前位的基
	long long remain = 0;	//当前位为1时，后面位剩余的数（即不完整的部分）中1出现的次数
	while(num)
	{
		current = num%10;
		num = num/10;

		if(current > 1)
			 count += (num+1)*base;
		else if(current == 1)
			count += num*base + (remain+1);
		else
			count += num*base;
	
		//下一位要用到的基和剩余不完整部分值
		remain += current*base; 
		base *= 10;
	}

	return count;
}

int main()
{
	long long a,b;
	//a,b的大小不定
	while(scanf("%lld %lld",&a,&b) != EOF)
	{
		long long result;
		if(a > b)
			result = CountNum1(a) - CountNum1(b-1);
		else
			result = CountNum1(b) - CountNum1(a-1);

		printf("%lld\n",result);
	}
	return 0;
}

/**************************************************************
    Problem: 1373
    User: mmc_maodun
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:912 kb
****************************************************************/