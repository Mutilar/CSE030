#include "HTable.h"
#include <iostream>
using namespace std;

HTable::HTable()
{
	HTable(23);
}
HTable::HTable(int t_size)
{
	dt = new data[t_size];
	max_size = t_size;

	for (int i = 0; i < max_size; i++)
	{
		dt[i].key = -1;
		dt[i].value = "N/A";
	}
	numel = 0;
}

int HTable::hash(int &k)
{
	return k%max_size;
}
int HTable::rehash(int &k)
{
	int new_k = k;
	new_k++;
	return hash(new_k);
}
int HTable::add(data &d)
{
	if (numel == max_size) return -1;
	else
	{
		int index = hash(d.key);
		if (dt[index].key == -1)
		{
			dt[index] = d;
			numel++;
			return 0;
		}
		else
		{
			for (int i = 0; i < max_size; i++)
			{
				index = rehash(index);
				if (dt[index].key == -1)
				{
					dt[index] = d;
					numel++;
					return 0;
				}
			}
		}
	}
}

int HTable::remove(data &d)
{
	int index = hash(d.key);
	if (dt[index].key == d.key)
	{
		dt[index].key = -1;
		dt[index].value = "N/A";
		numel--;
		return 0;
	}
	else
	{
		for (int i = 0; i < max_size; i++)
		{
			index = rehash(index);
			if (dt[index].key == d.key)
			{
				dt[index].key = -1;
				dt[index].value = "N/A";
				numel--;		
				return 0;
			}
		}
		return -1;
	}


}

void HTable::output()
{
	for (int i = 0; i < max_size; i++)
	{
		cout << i << " -> " << dt[i].key << "   " << dt[i].value << "\n";
	}
	cout<< "There are " << numel << " data in the table.";
}


