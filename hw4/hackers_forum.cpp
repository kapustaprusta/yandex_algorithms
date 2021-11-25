#include <map>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
	int messagesNumber = 0;
	std::cin >> messagesNumber;

	size_t maxMessagesNumber = 0;
	std::list<std::string> topics;
	std::map<int, std::string> messagesIdxAndTopics;
	std::multimap<std::string, int> topicsAndMessagesIdx;

	for (int messageIdx = 1; messageIdx <= messagesNumber; messageIdx++)
	{
		int replyMessageIdx = 0;
		std::cin >> replyMessageIdx;
		std::cin.ignore();

		std::string topic;
		std::string message;

		if (replyMessageIdx == 0)
		{
			getline(std::cin, topic);
			getline(std::cin, message);

			topics.push_back(topic);
			topicsAndMessagesIdx.insert(std::make_pair(topic,
													   messageIdx));
			messagesIdxAndTopics.insert(std::make_pair(messageIdx,
													   topic));
		}
		else
		{
			getline(std::cin, message);

			topic = messagesIdxAndTopics.at(replyMessageIdx);
			topicsAndMessagesIdx.insert(std::make_pair(topic,
													   messageIdx));
			messagesIdxAndTopics.insert(std::make_pair(messageIdx,
													   topic));

			
		}

		maxMessagesNumber = std::max(maxMessagesNumber,
									topicsAndMessagesIdx.count(topic));
	}

	for (const auto &crTopic : topics)
	{
		const size_t messagesCount = topicsAndMessagesIdx.count(crTopic);
		if (messagesCount >= maxMessagesNumber)
		{
			std::cout << crTopic << "\n";
			
			break;
		}
	}

	return 0;
}