#include <string>
#include <iostream>

int main()
{
	std::string bracketsSeq;
	std::cin >> bracketsSeq;

	int bracketsBalance = 0;
	for (int charIdx = 0; charIdx < bracketsSeq.size(); charIdx++)
	{
		if (bracketsSeq[charIdx] == ')' && bracketsBalance <= 0)
		{
			std::cout << "NO\n";

			return 0;
		}

		bracketsSeq[charIdx] == '(' ? bracketsBalance++
									: bracketsBalance--;
	}

	bracketsBalance == 0 ? std::cout << "YES\n"
						 : std::cout << "NO\n";

	return 0;
}