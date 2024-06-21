#include <fstream>

using namespace std;

class File_Proxy
{
protected:
    bool is_open = false;
    string file_name = "";
    fstream pointer;

    void handle_file_already_opened_error()
    {
        if (File_Proxy::is_open)
        {
            cout << "Error: File already opened!" << endl;
            exit(-1);
        }
    }

    void handle_file_not_opened_error()
    {
        if (!File_Proxy::is_open)
        {
            cout << "Error: File must be opened!" << endl;
            exit(-1);
        }
    }

    void open(std::ios_base::openmode purpose)
    {
        File_Proxy::handle_file_already_opened_error();

        File_Proxy::pointer.open(File_Proxy::file_name, purpose);
        File_Proxy::is_open = true;
    }

public:
    File_Proxy(string file_name)
    {
        File_Proxy::file_name = file_name;
    }

    int get_is_open()
    {
        return File_Proxy::is_open;
    }

    string get_file_name()
    {
        return File_Proxy::file_name;
    }

    void open_to_read()
    {
        File_Proxy::open(ios_base::in);
    }

    void open_to_write()
    {
        File_Proxy::open(ios_base::out);
    }

    void open_to_append()
    {
        File_Proxy::open(ios_base::app);
    }

    string read_line()
    {
        File_Proxy::handle_file_not_opened_error();

        string text;
        getline(File_Proxy::pointer, text);
        return text;
    }

    void write_line(string text)
    {
        File_Proxy::handle_file_not_opened_error();

        File_Proxy::pointer << text;
    }

    void append_line(string text)
    {
        File_Proxy::handle_file_not_opened_error();

        File_Proxy::pointer << text + "\n";
    }

    void close()
    {
        File_Proxy::handle_file_not_opened_error();

        File_Proxy::pointer.close();
        File_Proxy::is_open = false;
    }
};
