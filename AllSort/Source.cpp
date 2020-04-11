#include <iostream>
#include <vector>
#include <algorithm>

// ����
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
		// j + 1 cur key Ӧ���ڵ�λ��
		vec[j + 1] = CurKey;
	}
}

// ����
void inserSortDesc(std::vector<int>& vec)
{
	for (int i=1;i<vec.size();i++)
	{
		int j = i - 1;
		int curKey = vec[i];
		while (j >= 0 && curKey > vec[j])
		{
			vec[j + 1] = vec[j];		// ��������
			--j;
		}
		vec[j + 1] = curKey;
	}
}

// ѡ������
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

// �鲢
// p �鲢��ʼ����
// q �鲢�м�����
// r �鲢��������
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
	// �鲢����
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

// �������ʼ��������������
void MergeSort(std::vector<int>& vec, const int& p, const int& r)
{
	if (p >= r)
		return;

	// ȡ���е�
	int midPoint = (r + p) / 2;
	MergeSort(vec, p, midPoint);			// �ֽ����
	MergeSort(vec, midPoint + 1, r);		// �ֽ��ұ�
	MergeProc(vec, p, midPoint, r);
}

// ð�����򣬴������ٵ�����
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