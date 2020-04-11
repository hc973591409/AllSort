#include <iostream>
#include <vector>
#include <algorithm>

// 升序
void inserSort(std::vector<int> &vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		int CurKey = vec[i];
		int j = i - 1;          
		while ( j>=0 && CurKey < vec[j])
		{
			vec[j + 1] = vec[j];
			--j;
		}
		// j + 1 cur key 应该在的位置
		vec[j + 1] = CurKey;
	}
}

// 降序
void inserSortDesc(std::vector<int>& vec)
{
	for (int i=1;i<vec.size();i++)
	{
		int j = i - 1;
		int curKey = vec[i];
		while (j >= 0 && curKey > vec[j])
		{
			vec[j + 1] = vec[j];		// 依次右移
			--j;
		}
		vec[j + 1] = curKey;
	}
}

// 选择排序
void selectSort(std::vector<int>& vec)
{
	for (int i=0;i<vec.size()-1;++i)
	{
		int curMin = vec[i];
		int curIndex = i;
		for (int j=i+1;j<vec.size();++j)
		{
			if (curMin > vec[j])
			{
				curMin = vec[j];
				curIndex = j;
			}
		}
		if (curMin != vec[i])
			std::swap(vec[i], vec[curIndex]);
	}
}

// 归并
// p 归并起始索引
// q 归并中间索引
// r 归并结束索引
void MergeProc(std::vector<int>& vec,const int& p, const int& q, const int& r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<int>vec1(n1+1);
	std::vector<int>vec2(n2+1);
	vec1.assign(vec.begin() + p, vec.begin() + q+1);
	vec2.assign(vec.begin() + q + 1, vec.begin() + r+ 1);
	int indexL = 0;
	int indexR = 0;

	vec1.emplace_back(0xffff);
	vec2.emplace_back(0xffff);
	// 归并过程
	for (int i = p; i <= r; i++)
	{
		if (vec1[indexL] < vec2[indexR])
		{
			vec[i] = vec1[indexL];
			indexL++;
		}
		else
		{
			vec[i] = vec2[indexR];
			indexR++;
		}
	}
}

// 排序的起始索引，结束索引
void MergeSort(std::vector<int>& vec, const int& p, const int& r)
{
	if (p >= r)
		return;

	// 取得中点
	int midPoint = (r + p) / 2;
	MergeSort(vec, p, midPoint);			// 分解左边
	MergeSort(vec, midPoint + 1, r);		// 分解右边
	MergeProc(vec, p, midPoint, r);
}

// 冒泡排序，代码最少的排序
void BubbloSort(std::vector<int>& vec)
{
	for (int i=0; i<vec.size()-1; ++i)
		for (int j = vec.size() - 1; j > i; --j)
			if (vec[j]<vec[j-1])
				std::swap(vec[j], vec[j - 1]);
}


bool searCheach(std::vector<int>& vec, const int& num)
{
	int i = 0;
	while (i < vec.size())
	{
		if (num == vec[i++])
			return true;
	}
	return false;
}

void main()
{
	/*std::vector<int>m_vec{ 5,2,4,1,6,3 };
	inserSortDesc(m_vec);
	for_each(m_vec.begin(), m_vec.end(), [](const int& num) {std::cout << num << " "; });
	std::cout << '\n';
	selectSort(m_vec);
	for_each(m_vec.begin(), m_vec.end(), [](const int& num) {std::cout << num << " "; });*/
	// std::cout << searCheach(m_vec, 7) << std::endl;
	std::vector<int>m_vec{ 5,4,2,7,1,6,3,2 };
	BubbloSort(m_vec);
	for_each(m_vec.begin(), m_vec.end(), [](const int& num) {std::cout << num << " "; });
	std::cin.get();
}