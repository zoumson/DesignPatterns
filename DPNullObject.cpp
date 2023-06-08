#include "DPNullObject.h"

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace nob
            {

                void ConsoleLogger::log(const std::string& message)
                {
                    std::cout << message << "\n";
                };

                void FileLogger::log(const std::string& message)
                {
                    std::cout << "Printing message to file " << filePath << ": " << message << "\n";
                };

                void ApiLogger::log(const std::string& message)
                {
                    std::cout << "Sending message to api " << url << ": " << message << "\n";
                };


                SomeTask::~SomeTask()
                {
                    delete logger;
                };
                void SomeTask::execute()
                {
                    // Do some stuff...

                    logger->log("Did some stuff");

                    // Do some other stuff...

                    logger->log("Did some other stuff");

                    // One last thing...

                    logger->log("Task complete!");
                }

            }
        }
	}
}