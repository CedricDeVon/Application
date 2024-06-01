class Stopwatch
{
private:
    int is_running = 0;
    int duration_in_seconds = 0;
    time_t start_time = 0;
    time_t stop_time = 0;

    void handle_not_stopeed_error()
    {
        if (is_running && stop_time == 0)
        {
            printf("Error: Stopwatch has not yet stopped!");
            exit(-1);
        }
    }
    void handle_already_started_error()
    {
        if (is_running)
        {
            printf("Error: Stopwatch has already started!");
            exit(-1);
        }
    }

    void handle_already_stopped_error()
    {
        if (!is_running)
        {
            printf("Error: Stopwatch has already stopped!");
            exit(-1);
        }
    }

public:
    int get_is_running()
    {
        return Stopwatch::is_running;
    }

    int get_duration_in_seconds()
    {
        Stopwatch::handle_not_stopeed_error();

        return Stopwatch::stop_time - Stopwatch::start_time;
    }

    time_t get_start_time()
    {
        return Stopwatch::start_time;
    }

    time_t get_stop_time()
    {
        return Stopwatch::stop_time;
    }

    int start()
    {
        Stopwatch::handle_already_started_error();

        is_running = 1;
        Stopwatch::start_time = time(NULL);
        return Stopwatch::start_time;
    }

    int stop()
    {
        Stopwatch::handle_already_stopped_error();

        is_running = 0;
        Stopwatch::stop_time = time(NULL);
        return Stopwatch::stop_time;
    }

    void reset()
    {
        Stopwatch::handle_already_stopped_error();

        is_running = 0;
        Stopwatch::start_time = 0;
        Stopwatch::stop_time = 0;
    }
};
