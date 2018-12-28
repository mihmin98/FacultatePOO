#pragma once
#include <vector>

template <class Entity>
class Repository
{
public:
	Repository();
	~Repository();

	void Add(Entity* toAdd);
	void Remove(Entity* toRemove);
	std::vector<Entity*> GetAll();

protected:
	std::vector<Entity*> entries;
};

template<class Entity>
inline Repository<Entity>::Repository()
{
}

template<class Entity>
inline Repository<Entity>::~Repository()
{
	for (int i = 0; i < entris.size(); i++) {
		delete entries[i];
	}
	entries.clear();
}

template<class Entity>
inline void Repository<Entity>::Add(Entity * toAdd)
{
	entries.push_back(toAdd);
}

template<class Entity>
inline void Repository<Entity>::Remove(Entity * toRemove)
{
	//find entity
	int pos = -1;
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i] == toRemove) {
			pos = i;
			break;
		}
	}

	if (pos != -1) {
		delete entries[pos];
		entries.erase(entries.begin() + pos);
	}
}

template<class Entity>
inline std::vector<Entity*> Repository<Entity>::GetAll()
{
	return entries;
}
