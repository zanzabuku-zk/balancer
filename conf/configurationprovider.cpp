// configurationprovider.cppm

export module configurationprovider;

export class ConfigurationProvider
{
private:
	static ConfigurationProvider instance;

public:
	ConfigurationProvider* getConfiguration()
	{
		return &instance;
	}
};
