#include "publisher.h"

void Publisher::subscribe(Wrapper* wrapper) {
	subscribers.push_front(wrapper);
}

void Publisher::unsubscribe(Wrapper* wrapper) {
	auto it = std::find(subscribers.begin(), subscribers.end(), wrapper);
    if (it != subscribers.end()) {
    	delete *it;
    	subscribers.erase(it);
    }
}

void Publisher::notifySubscribers(const std::string& context) const {
	for (const auto& subscriber: subscribers) {
		subscriber->write(context);
	}
}