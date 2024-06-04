
using namespace std;

class User_File_Data : public File_Data
{
public:
    User_File_Data(string email, string password, string first_name, string last_name, int age)
    {
        User_File_Data::append_value(email);
        User_File_Data::append_value(password);
        User_File_Data::append_value(first_name);
        User_File_Data::append_value(last_name);
        User_File_Data::append_value(to_string(age));
    }
};
