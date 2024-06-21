
using namespace std;

class File_Data
{
protected:
    int value_count = 0;
    string values = "";

    void append_value(string value)
    {
        File_Data::append_value_separator();
        File_Data::values += value;
        File_Data::value_count += 1;
    }

    void append_value_separator()
    {
        File_Data::values += constants.FILE_DATA_VALUE_BREAK;
    }

public:
    int get_value_count()
    {
        return File_Data::value_count;
    }

    string get_values()
    {
        return File_Data::values;
    }
};