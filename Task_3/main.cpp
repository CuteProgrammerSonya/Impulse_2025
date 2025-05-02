#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <stack>

void all_permutations_recursive(std::string& letter, int i, int n, std::unordered_set<std::string>& result)
{
	if (i == n - 1)
	{
		result.insert(letter);
		return;
	}
	for (int j = i; j < n; j++)
	{
		if (i != j && letter[i] == letter[j])
		{ 
			continue;
		}
		std::swap(letter[i], letter[j]);
		all_permutations_recursive(letter, i + 1, n, result);
		std::swap(letter[i], letter[j]);
	}
}

void all_permutations_iterative(std::string& letter, std::unordered_set<std::string>& result) 
{
	std::stack<std::pair<std::string, int>> stack;
	stack.push({letter, 0});

	while (!stack.empty()) 
	{
		std::pair<std::string, int> current_pair;
		current_pair = stack.top();
		std::string current_letter = current_pair.first;
		int index = current_pair.second;
		stack.pop();

		if (index == current_letter.size()) 
		{
			result.insert(current_letter);
			continue;
		}

		for (int i = index; i < current_letter.size(); i++) 
		{
			if (i != index && current_letter[i] == current_letter[index])
			{
				continue;
			}
			std::swap(current_letter[index], current_letter[i]);
			stack.push({current_letter, index + 1});
			std::swap(current_letter[index], current_letter[i]);
		}
	}
}

void print_set(const std::unordered_set<std::string>& set)
{
	for (const std::string& word : set) 
	{
		std::cout << word << std::endl;
	}
}

int main()
{
	std::string str = { 0 };
	std::unordered_set<std::string> recursive_result = {};
	std::unordered_set<std::string> iterative_result = {};
	std::cout << "Enter string: ";
	std::cin >> str;
	all_permutations_recursive(str, 0, str.size(), recursive_result);
	print_set(recursive_result);
	std::cout << std::endl;
	all_permutations_iterative(str, iterative_result);
	print_set(iterative_result);
	return 0;
}

