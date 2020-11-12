#pragma once

#include <Environment.h>
namespace tw
{
	class EnvironmentManager
	{
	private:
		static Environment * testEnvironment;
		void createTestEnvironmentIfNotExists();


		static EnvironmentManager * instance;
		EnvironmentManager()
		{

		}

	public:
		static EnvironmentManager * getInstance();

		Environment * loadEnvironment(int environmentId);
		void saveEnvironment(Environment * environment);

		Environment * getRandomEnvironment()
		{
			createTestEnvironmentIfNotExists();
			return testEnvironment;
		}
	};
}