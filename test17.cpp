/*
��Ŀ�����������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.����
    ������ҪҪ�����������棺
    1������ж���Щ�ַ�����Ҫɾ�����ַ���ͬ�ܶ��ַ�������һ�������Կ���һ����ϣ���飬ȫ����ʼ��Ϊfalse�����ڶ����ַ������ַ���Ӧ��ӳ��λ����Ϊture����ʾ��Щλ�ö�Ӧ���ַ��ڵ�һ���ַ�������Ҫɾ����
    2������ɾ���ַ��Ĳ�����ÿ��ɾ��һ��������Ѻ����Ԫ�ؾ�����һλ������Ҫɾ�����ַ������ж�������ַ�����ʱ�临�Ӷ�ΪO��n*n��������������O��n����ɾ�����������ǿ������룬��һ���ַ���Ҫ��ɾ����ʱ�����ǰ�����ռ��λ������������ַ������Ҳ���൱������ַ���ɾ���ˡ��ھ���ʵ���У����ǿ��Զ�������ָ��(pFast��pSlow)����ʼ��ʱ��ָ���һ�ַ�����ʼλ�á���pFastָ����ַ�����Ҫɾ�����ַ�����pFastֱ��������ָ����һ���ַ������pFastָ����ַ��ǲ���Ҫɾ�����ַ�����ô��pFastָ����ַ���ֵ��pSlowָ����ַ�������pFast��pStartͬʱ����ƶ�ָ����һ���ַ���������ǰ�汻pFast�������ַ��൱�ڱ�ɾ���ˡ������ַ���������ɾ����O(n)ʱ���ھͿ�����ɡ�
    ǰ��Ҳ��ƪɾ���ظ��ַ��Ĳ����õ��˸�ɾ�������������http://blog.csdn.net/ns_code/article/details/21328151��
    ���⣬��һ����Ҫע�⣬char�ķ�Χ��-128-127��unsigned char�ķ�Χ������0-255�����ASCIIֵ��128-255֮����ַ����������Ϊ��char�ͣ���ת��Ϊintֵ�ķ�Χ����-128--1֮�䣬���������Ĵ����������֡�
*/

#include<stdio.h>  
#include<string.h>  
#define MAX 256  
      
void DeleteChars(char *str1,char *str2)  
{  
    if(str1==NULL || str2==NULL)  
        return;  
      
    bool hashtable[MAX];  
    memset(hashtable,0,sizeof(hashtable));  
      
    //��str2���ַ���Ӧ��hashtable�����е�λ���ϵ�ֵ��Ϊture  
    while(*str2 != '\0')  
    {  
        //ASCIIֵ��128-255֮��ĵ��ַ���  
        //��char���棬ת��Ϊint��,��-128--1֮��  
        int index;  
        if(*str2 >= 0)  
            index = *str2;  
        else  
            index = *str2 + 256;  
      
        hashtable[index] = true;  
        ++str2;  
    }  
      
    char *pFast = str1;  
    char *pSlow = str1;  
    while(*pFast != '\0')  
    {  
        int index;  
        if(*pFast >= 0)  
            index = *pFast;  
        else  
            index = *pFast + 256;  
      
        //�����Ƿ�����Ҫɾ�����ַ���pFast�����ƣ�  
        //ֻ��û����Ҫɾ�����ַ�ʱ��pSlow�ź���  
        if(!hashtable[index])  
            *pSlow++ = *pFast;    
        ++pFast;  
    }  
    *pSlow = '\0';  
}  
      
int main()  
{  
      
    char str1[] = "They are students";  
    char str2[] = "Tdentt";  
    DeleteChars(str1,str2);  
    puts(str1);  
    return 0;  
}  