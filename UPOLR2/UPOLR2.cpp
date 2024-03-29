// UPOLR2.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include <list>
#include <string>
#include <cctype>

bool search(std::string str);
std::string calculation(std::string str);
int number(std::string str, int j, bool k);
std::string parsing(std::string str);
std::string ex(std::string str);
int neg(std::string str);
bool neg1(std::string str);
//void prof();

int main()
{
	std::string str;
	std::getline(std::cin, str);
	str = parsing(str);
	//str = neg(str);
	//system("pause");
	str = ex(str);
	//system("pause");
	//prof();
    return 0;
}

//void prof()
//{
//	int i;
//	std::string str;
//	for (i = 0; i < 10000; i++)
//	{
//		str = "(20+5)*(5-2)/5";
//		str = parsing(str);
//	}
//
//	for (i = 0; i < 10000; i++)
//	{
//		str = "(20+5)*(5-2)/5";
//		str = ex(str);
//	}
// }


std::string parsing(std::string str)
{
	str = str + "#";
	int prav = 15;
	unsigned int x = 0, i, j;
	
	char stroki[14] = { 'S', 'T', 's', 't', 'U', 'W', '+', '-', '*', '/', '(', ')', 'n', '#' };
	char stolb[8] = { '+', '-', '*', '/', '(', ')', 'n', '#' };
	int tabl[14][8] =
	{ { 0,  1,  0,  0,  1,  0,  1,  0 },
	{ 0,  5,  0,  0,  5,  0,  5,  0 },
	{ 2,  3,  0,  0,  0,  4,  0,  4 },
	{ 8,  8,  6,  7,  0,  8,  0,  8 },
	{ 0,  10, 0,  0,  9,  0, 11,  0 },
	{ 13, 13, 13, 13, 0, 13, 12, 13 },
	{ -1, 0,  0,  0,  0,  0,  0,  0 },
	{ 0, -1,  0,  0,  0,  0,  0,  0 },
	{ 0,  0, -1,  0,  0,  0,  0,  0 },
	{ 0,  0,  0, -1,  0,  0,  0,  0 },
	{ 0,  0,  0,  0, -1,  0,  0,  0 },
	{ 0,  0,  0,  0,  0, -1,  0,  0 },
	{ 0,  0,  0,  0,  0,  0, -1,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  14 } };

	std::list <char> List;
	List.push_back('#');
	List.push_back('S');

	while (prav != 14 && prav != 0)
	{
		if (isdigit(List.back()))
			i = 12;
		else
		{
			for (i = 0; i < 14; i++)
			{
				if (stroki[i] == List.back())
					break;
			}
		}
		if (isdigit(str[x]))
			j = 6;
		else
		{
			for (j = 0; j < 8; j++)
			{
				if (stolb[j] == str[x])
					break;
			}
		}
		prav = tabl[i][j];
		switch (prav)
		{
		case 0:
			//std::cout << "\nError\n";
			str = "error";
			//str[str.length()-1] = 'h';
			return str;
			break;
		case 1:
			List.pop_back();
			List.push_back('s');
			List.push_back('T');
			break;
		case 2:
			List.pop_back();
			List.push_back('s');
			List.push_back('T');
			List.push_back('+');
			break;
		case 3:
			List.pop_back();
			List.push_back('s');
			List.push_back('T');
			List.push_back('-');
			break;
		case 4:
			List.pop_back();
			break;
		case 5:
			List.pop_back();
			List.push_back('t');
			List.push_back('U');
			break;
		case 6:
			List.pop_back();
			List.push_back('t');
			List.push_back('U');
			List.push_back('*');
			break;
		case 7:
			List.pop_back();
			List.push_back('t');
			List.push_back('U');
			List.push_back('/');
			break;
		case 8:
			List.pop_back();
			break;
		case 9:
			List.pop_back();
			List.push_back(')');
			List.push_back('S');
			List.push_back('(');
			break;
		case 10:
			List.pop_back();
			List.push_back('W');
			List.push_back('-');
			break;
		case 11:
			List.pop_back();
			List.push_back('W');
			break;
		case 12:
			List.pop_back();
			List.push_back('W');
			List.push_back(str[x]);
			break;
		case 13:
			List.pop_back();
			break;
		case -1:
			List.pop_back();
			x++;
			break;
		case 14:
			//std::cout << "\nSuccess parsing\n";
			break;
		}
	}

	str.erase(str.begin() + str.length() - 1, str.end());
	//std::cout << str << std::endl;
	
	//str[str.length() - 1] = 'h';
	return str;
}

int neg(std::string str)
{
		std::string Integer = str;
		if (str[0] == '-')
			return atoi(Integer.c_str());
		else
			return atoi(Integer.c_str());
}

bool neg1(std::string str)
{
		if (str[0] == '-')
			return true;
		else
			return false;
}

std::string ex(std::string str)
{
	bool closed = false;
	int i, l, r, in,last_in;
	while (!search(str))
	{
		l = 0;
		r = 0;
		in = 0;
		last_in = 0;
		std::string substrn;
		for (i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
			{
				in++;
				if (in >= last_in)
				{
					l = i;
					last_in = in;
					closed = false;
				}
			}
			if (str[i] == ')')
			{
				if (closed == false)
				{
					r = i;
					closed = true;
				}
				in--;
			}
		}
		if (r-l == str.length()||r==0)
		{
			str = calculation(str);
			if (str == "error")
			{
				//std::cout << "\nError\n";
				return(str);
			}
		}
		else
		{
			substrn = calculation(str.substr(l + 1, r - l - 1));
			if (str == "error")
			{
				//std::cout << "\nError\n";
				return(str);
			}
			str = str.erase(l, r - l + 1);
			str = str.insert(l, substrn);
		}
		//std::cout << "ans = " << str << "." << std::endl;
	}
	//str[str.length() - 1] = 'h';
	return str;
}

bool search(std::string str)
{
	unsigned int i;
	for (i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			if(str.length()==2 && str[0]=='-' || str.length() == 3 && str[0] == '-')
			return 1;
			else
			return 0;
	}
	//return 0;
	return 1;
}

//int counter()

void substrings(std::string &substr1, std::string &substr2,std::string str, int &a,int &b, int &koef, bool &check, int i)
{
	a = number(str, i - 1, 0);
	int a2 = i - number(str, i - 1, 0);
	if (a != 0)
		substr1 = str.substr(a - 1, a2 + 1);
	else
		substr1 = str.substr(a, a2);
	b = number(str, i + 1, 1);
	int b1 = i + 1;
	if (str[b1] == '-')
		substr2 = str.substr(b1, b - i + 2);
	else
		substr2 = str.substr(b1, b - i);
	if (neg1(substr1))
	{
		check = true;
		koef++;
	}
	if (neg1(substr2))
		koef+=2;
}

std::string calculation(std::string str)
{
	unsigned int i;
	std::string substr1;
	std::string substr2;
	int a, b, n = 0,koef=0;
	bool check = false;
	while (!search(str))
	{
		if(!n)
			for (i = 0; i < str.length(); i++)
			{
				if (str[i] == '*')
				{
					substrings(substr1, substr2, str, a, b, koef, check, i);
					substr1 = std::to_string(neg(substr1) * neg(substr2));
					//koef--;
					break;
				}
				else if (str[i] == '/')
				{
					substrings(substr1, substr2, str, a, b, koef, check, i);
					substr1 = std::to_string(neg(substr1) / neg(substr2));
					break;
				}
			}
		if (i == str.length())
			n++;
		if (n)
		{
			for (i = 0; i < str.length(); i++)
			{
				if (str[i] == '+')
				{
					substrings(substr1, substr2, str, a, b, koef, check, i);
					substr1 = std::to_string(neg(substr1) + neg(substr2));
					break;
				}
				else if (str[i] == '-'&&i!=0)
				{
					substrings(substr1, substr2, str, a, b, koef, check, i);
					substr1 = std::to_string(neg(substr1) - neg(substr2));
					break;
				}

			}
		}
		//str = str.erase(a, b - a + 1);
		if (check)
		{
			str = str.erase(a - 1, b - a + 1 + koef);
			str = str.insert(a - 1, substr1);
		}
		else
		{
			str = str.erase(a, b - a + 1 + koef);
			str = str.insert(a, substr1);
		}
		check = false;
		koef = 0;
	}

	//str[str.length()-1] = 'h';
	return str;
}

int number(std::string str, int j, bool k)
{
	if (!k)
	{
		while (isdigit(str[j]))
			if (j != 0)
				j--;
			else
				return (-j);
				//return j;
		j++;
	}
	else
	{
		while (isdigit(str[j]))
			if (j != str.length() - 1)
				j++;
			else
				//return (-j);
				return j;
		j--;
	}
	//return (-j);
	return j;
}
