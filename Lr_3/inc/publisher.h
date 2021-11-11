#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <list>
#include "wrapper.h"

class Publisher {
protected:
	std::list<Wrapper*> subscribers;
public:
	void subscribe(Wrapper* wrapper);
	void unsubscribe(Wrapper* wrapper);
	void notifySubscribers(const std::string& context) const;
};

#endif