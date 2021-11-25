#include <map>
#include <list>
#include <string>
#include <iostream>
#include <unordered_set>

struct Word
{
	std::string name_;
	std::map<char, int> charsCounters_;
	int evidences_;
};

void printSuspects(std::list<std::string> plates,
				   std::list<std::string> evidences)
{
	std::list<Word> platesWords;
	for (const auto &crPlate : plates)
	{
		std::map<char, int> tmpCharsCounters;
		for (int i = 0; i < crPlate.size(); i++)
		{
			tmpCharsCounters[crPlate[i]]++;
		}

		platesWords.emplace_back(Word{crPlate,
									  tmpCharsCounters});
	}

	std::list<Word> evidencesWords;
	for (const auto &crEvidence : evidences)
	{
		std::map<char, int> tmpCharsCounters;
		for (int i = 0; i < crEvidence.size(); i++)
		{
			tmpCharsCounters[crEvidence[i]]++;
		}

		evidencesWords.emplace_back(Word{crEvidence,
									  tmpCharsCounters});
	}

	int maxEvidenceCounter = 0;
	std::list<Word> platesAndEvidencesCounter;

	for (auto &crPlateWord : platesWords)
	{
		int evidenceCounter = 0;
		for (const auto &crEvidenceWord : evidencesWords)
		{
			int charsCounter = 0;
			for (const auto &crEvidenceChar : crEvidenceWord.charsCounters_)
			{
				if (crPlateWord.charsCounters_.find(crEvidenceChar.first) != crPlateWord.charsCounters_.end())
				{
					charsCounter++;
				}
			}

			if (charsCounter == crEvidenceWord.charsCounters_.size())
			{
				evidenceCounter++;
			}
		}

		crPlateWord.evidences_ = evidenceCounter;
		platesAndEvidencesCounter.push_back(crPlateWord);
		maxEvidenceCounter = std::max(evidenceCounter, maxEvidenceCounter);
	}

	for (const auto &crPlateAndEvidencesCounter : platesAndEvidencesCounter)
	{
		if (crPlateAndEvidencesCounter.evidences_ >= maxEvidenceCounter)
		{
			std::cout << crPlateAndEvidencesCounter.name_ << "\n";
		}
	}
}

int main()
{
	int evidencesNumber = 0;
	std::cin >> evidencesNumber;
	std::list<std::string> evidences;

	std::string tmpString;
	for (int i = 0; i < evidencesNumber; i++)
	{
		std::cin >> tmpString;
		evidences.emplace_back(std::move(tmpString));
	}

	int platesNumber = 0;
	std::cin >> platesNumber;
	std::list<std::string> plates;

	for (int i = 0; i < platesNumber; i++)
	{
		std::cin >> tmpString;
		plates.emplace_back(std::move(tmpString));
	}

	printSuspects(std::move(plates),
				  std::move(evidences));

	return 0;
}