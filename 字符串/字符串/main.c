#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//const char string
//unsigned int Mystrlen(const char *str )
//{
//	assert(str != NULL);
//	unsigned int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//
//}
//char * Mystrcpy(char * dest, const char *src)
//{
//	assert(src != NULL&& dest != NULL);
//	char * p = dest;
//	while (*dest++ = *src++);
//	/*while (*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = '\0';*/
//	return p;
//}
//int main()
//{
//	char *src = "hello";
//	char dest[10] = { 0 };
//	//strcpy(dest, src);
//	//printf("%s ", dest);
//	printf("%s", Mystrcpy(dest,src));
//	
//	/*int len = Mystrlen(arr);
//	printf("%d ", len);*/
//	//printf("%d ", strlen(arr));
//	system("pause");
//	return 0;
//}
//char * Mystrcat(char * dest, const char * src)
//{
//	assert(dest != NULL && src != NULL);
//	char * p = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++);
//	return p;
//	
//}
//int main()
//{
//	char dest[20] = "hello ";
//	char *src = "bit";
//	Mystrcat(dest, src);
//	printf("%s ", dest);
//	system("pause");
//	return 0;
//
//}
//int Mystrcmp(const char * str1, const char * str2)
//{
//	//如果str1 = str2 str1和str2同时++ （除\0)
//	//如果不同，比较。
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	//if (*str1 > *str2)
//	//{
//	//	return 1;
//	//}
//	//else
//	//{
//	//	return -1;
//	//}
//	return *str1 > *str2 ? 1 : -1;
//}
//int main()
//{
//	char *arr = "ahello";
//	char *arr1 = "hello";
//	int n = Mystrcmp(arr, arr1); //相等返回0；第一个大，返回1；第二个大，返回-1.
//	//比较ascll
//	printf("%d ", n);
//	system("pause");
//	return 0;
//}

//char * Mystrncpy(char * dest, const char * src, int n)
//{
//	assert(src != NULL&& dest != NULL);
//		char * p = dest;
//		int i = 0;
//		while ( i < n)
//		{
//			(*dest++ = *src++);
//			i++;
//		}
//		return p;
//		
//}
//
//int main()
//{
//	char dest[20] = "abc";
//	char *src = "hello";
//	 //拷贝src的前n个字符。
//	printf("%s \n", Mystrncpy(dest, src, 2));
//	system("pause");
//	return 0;
//}
//
//char * Mystrncat(char  *dest, const char *src, int n)
//{
//	assert(src != NULL&& dest != NULL);
//	char *p = dest;
//	int i = 0;
//	while (*dest != '\0')
//	{
//		*dest++;
//	}
//	while (i < n)
//	{
//		*dest++ = *src++;
//		i++;
//	}
//	*dest = '\0';
//	return p;
//}
//int main()
//{
//	char str[10] = "abcd";
//	char *src = "efgh";
//	printf("%s \n", Mystrncat(str, src, 2));
//	system("pause");
//	return 0;
//}
//
//int  Mystrncmp(const char * str1, const char * str2, int n)
//{
//	int diff = 0;
//	int i = 0;
//	while (i < n && (diff = (*str1 - *str2)) == 0 && *str1 != '\0')
//	{
//		str1++;
//		str2++;
//		i++;
//	}
//	return diff ; 
//}
//
//int main()
//{
//	char * str1 = "bdacd";
//	char * str2 = "bdef";
//	 printf("%d \n", Mystrncmp(str1, str2, 3));
//	system("pause");
//	return 0;
//}


//const char *Mystrstr1(const char * str1, const char * str2) //错误
//{
//	assert(str1 != NULL && str2 != NULL);
//	const char * p = str1;
//	while (str1 != '\0')
//	{
//		while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		if (*str1 == '\0')
//		{
//			return NULL;
//		}
//		if (*str2 == '\0')
//		{
//			return p;
//		}
//		str1++;
//	}
//	return NULL;
//}

//const char *Mystrstr(const char * str1, const char * str2)
//{
//	assert(str1 != NULL && str2 != NULL);
//	const char * s1 = str1;
//	const char * s2 = str2;
//	const char * start = s1;
//	while (*start != '\0')
//	{
//		s1 = start;
//		s2 = str2;
//		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s1 == '\0')
//		{
//			return NULL;
//		}
//		if (*s2 == '\0')
//		{
//			return start;
//		}
//		start++;
//	}
//	return NULL;
//}
//int main()
//{
//	char *str1 = "abbbcdef";
//	char *str2 = "bbc";
//	const char * p =Mystrstr(str1, str2);
//	printf("%s ", p);
//	system("pause");
//	return 0;
//}

//void Function(int * left, int *right)
//{
//	while (left < right)
//	{
//		while ((left < right) && (*left % 2 == 1))
//		{
//			left++;
//		}
//		while ((left < right) && (*right % 2 == 0))
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = *left;
//			*left = *right;
//			*right = tmp;
//		}
//	}
//}
//
//void Show(int arr[],int n)
//{
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int n = sizeof (arr) / sizeof (arr[0]);
//	Function(arr, arr + n - 1);
//	Show(arr,n);
//	system("pause");
//	return 0;
//}


//void reverse(char *left, char *right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//
//}
//void left_move(char * str, int k)
//{
//	reverse(str, str + k - 1);
//	reverse(str + k, str+strlen(str) - 1);
//	reverse(str, str + strlen(str) - 1);
//}

//int Is_left_move(char *arr, const char * p)
//{
//	/*int i = 0;
//	for (i = 0; i < strlen(str); i++)
//	{
//		left_move(str, 1);
//		if (strcmp(str, src)== 0);
//		{
//			return 1;
//		}
//	}
//	return 0;*/
//
//	strncat(arr, arr, strlen(arr));
//	if (strstr(arr, p) != NULL);
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	//char str[] = "abcdefg";
//	//left_move(str, 3);
//	char str1[100] = "aabcd";
//	char * str2= "bcdda";
//	int ret = Is_left_move(str1, str2);
//	printf("%d ", ret);
//	system("pause");
//	return 0;
//}


//int main() //strtok 切割字符串
//{
//
//	char str[] = "ABCDE@FG.HIJKL-ERT";
//	char * ret = strtok(str, "@.-");
//	while (ret != NULL)
//	{
//		printf("%s\n", ret);
//		ret = strtok(NULL, "@.-");
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//
//	printf("%s \n", strerror(1));
//	system("pause");
//	return 0;
//}
//
void *Mymemcpy(void *dest, const void *src, int num)
{
	char * p = (char *)dest;
	char * q = (char *)src;
	void *ret = dest;
	while (num--)
	{
		*(char *)dest = *(char *)src;
		p++;
		q++;

	}
	return ret;
}
int main() //memcpy 内存拷贝函数 输入字节数
{
	int arr1[20] = { 0 };
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//char str1[] = "abcdef";
	//char str2[20] = { 0 };

	//memcpy(str2, str1, 4);
	printf("%s ", Mymemcpy(arr1, arr2, 4));
	system("pause");
	return 0;
}
