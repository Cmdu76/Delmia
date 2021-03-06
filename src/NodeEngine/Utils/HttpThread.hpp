#ifndef HTTPTHREAD_HPP
#define HTTPTHREAD_HPP

#include <functional>
#include <vector>

#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Http.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Thread.hpp>

namespace lp
{

class HttpThread
{
    public:
        HttpThread();
        HttpThread(std::string const& url, std::string const& uri);
        ~HttpThread();

        void run();

        void setAddress(std::string const& url, std::string const& uri);
        void setMessage(std::string const& message);

    private:
        sf::Thread mThread;
        sf::Mutex mMutex;

        bool mRunning;

        std::vector<std::string> mMessages;

        std::string mUrl;
        std::string mUri;
};

} // namespace lp

#endif // HTTPTHREAD_HPP
