#include <map>
#include <list>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

const int cAllSeats = 450;

int main()
{
	int allVotes = 0;
	std::list<std::string> partiesNames;
	std::map<std::string, int> partiesAndSeats;
	std::map<std::string, int> partiesAndVotes;
	std::vector<std::pair<std::string, std::pair<int, float>>> partiesAndVotesAndReminders;

	while (true)
	{
		std::string tmpPartyAndVotes;
		getline(std::cin, tmpPartyAndVotes);

		if (tmpPartyAndVotes.empty())
		{
			break;
		}

		std::string tmpWord;
		std::vector<std::string> tmpWords;
		std::istringstream inputTextStream(tmpPartyAndVotes);

		while (inputTextStream >> tmpWord)
		{
			tmpWords.emplace_back(tmpWord);
		}

		int tmpPartyVotes = 0;
		std::string tmpPartyName;

		for (int i = 0; i < tmpWords.size() - 1; i++)
		{
			tmpPartyName += tmpWords[i] + " ";
		}
		tmpPartyVotes = atoi(tmpWords.back().c_str());

		allVotes += tmpPartyVotes;
		partiesNames.push_back(tmpPartyName);
		partiesAndVotes[tmpPartyName] += tmpPartyVotes;
	}

	int distributedSeats = 0;
	float firstElectoralQuotient = allVotes / float(cAllSeats);

	for (const auto &crPartyAndVotes : partiesAndVotes)
	{
		int tmpSeats = 0;
		if (firstElectoralQuotient != 0)
		{
			tmpSeats = crPartyAndVotes.second / firstElectoralQuotient;
		}
		const float cReminder
					= float(crPartyAndVotes.second) - tmpSeats * firstElectoralQuotient;
		
		distributedSeats += tmpSeats;
		partiesAndSeats[crPartyAndVotes.first] = tmpSeats;
		partiesAndVotesAndReminders.push_back(std::make_pair(crPartyAndVotes.first,
															 std::make_pair(crPartyAndVotes.second, cReminder)));
	}

	std::sort(partiesAndVotesAndReminders.begin(),
			  partiesAndVotesAndReminders.end(),
			  [](const std::pair<std::string, std::pair<int, float>> &crLhs,
			  	 const std::pair<std::string, std::pair<int, float>> &crRhs) -> bool
				{
					if (crLhs.second.second == crRhs.second.second)
					{
						return crLhs.second.first > crRhs.second.first;
					}

					return crLhs.second.second > crRhs.second.second;
				});

	int partyIdx = 0;
	int remainingSeats = cAllSeats - distributedSeats;
	
	while (remainingSeats != 0)
	{
		const int tmpPartyIdx
						= partyIdx % partiesAndVotesAndReminders.size();
		const std::string tmpPartyName
						= partiesAndVotesAndReminders[tmpPartyIdx].first;
		partiesAndSeats[tmpPartyName]++;

		partyIdx++;
		remainingSeats--;
	}

	for (const auto &crPartyName : partiesNames)
	{
		std::cout << crPartyName
				  << partiesAndSeats[crPartyName] << "\n";
	}

	return 0;
}