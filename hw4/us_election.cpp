#include <map>
#include <string>
#include <sstream>
#include <iostream>

int main()
{
	std::map<std::string, int> candidatesAndVotes;
	while (true)
	{
		std::string tmpCandidateAndVotes;
		getline(std::cin, tmpCandidateAndVotes);

		if (tmpCandidateAndVotes.empty())
		{
			break;
		}

		int tmpVotes = -1;
		std::string tmpCandidate;
		std::istringstream inputStream(tmpCandidateAndVotes);

		for (int j = 0; j < 2; j++)
		{
			j % 2 == 0 ? inputStream >> tmpCandidate
					   : inputStream >> tmpVotes;
		}

		candidatesAndVotes[tmpCandidate] += tmpVotes;
	}

	for (const auto &crCandidateAndVotes : candidatesAndVotes)
	{
		std::cout << crCandidateAndVotes.first << " " << crCandidateAndVotes.second << "\n";
	}

	return 0;
}