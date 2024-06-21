
using namespace std;

class User_File_Proxy : public File_Proxy
{
public:
    User_File_Proxy() : File_Proxy("./database/users.txt")
    {
    }
};

User_File_Proxy user_file_proxy;