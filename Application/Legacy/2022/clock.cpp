
class Clock
{
public:
    static time_t get_unix_time()
    {
        return time(NULL);
    }

    static char *get_local_time()
    {
        time_t unix_time = Clock::get_unix_time();
        return asctime(localtime(&unix_time));
    }
};

