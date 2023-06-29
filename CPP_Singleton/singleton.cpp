#include <iostream>

/* Singleton example*/
class Random
{
public:
	/* Delete the copy constructor */
	Random(const Random&) = delete;

	static Random& Get()
	{
		static Random instance;
		return instance;
	}

	static float Float() { return Get().IFloat(); }

private:
	Random() {}
	float IFloat() { return m_RandomGenerator; }
	
	float m_RandomGenerator = 0.5f;

};


int main()
{
	float number = Random::Float();

	std::cout << number << std::endl;

	return 0;
}